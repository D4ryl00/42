/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:25:43 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 13:32:08 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>

static void	merge_list_of_dirs(t_list **dist, t_list **dirs)
{
	t_list	*last;
	t_list	*save;

	if (dist && dirs && *dirs)
	{
		save = *dist;
		*dist = *dirs;
		last = *dirs;
		while (last->next)
			last = last->next;
		last->next = save;
	}
}

static void	fill_file(t_file *file, struct dirent *dir, t_args *args)
{
	if (ft_strequ(args->dirs->content, "/"))
		ft_sprintf(&(file->path), "/%s", dir->d_name);
	else
		ft_sprintf(&(file->path), "%s/%s", args->dirs->content
				, dir->d_name);
	if (!file->path || !(file->name = ft_strdup(dir->d_name)))
		exit(1);
}

static void	extract_child_to_list(t_args *args, DIR *dir)
{
	t_list			*node;
	t_file			*file;
	struct dirent	*child;

	while ((child = readdir(dir)))
	{
		if (!args->options.a && child->d_name[0] == '.')
			continue ;
		if (!(file = (t_file *)malloc(sizeof(t_file)))
				|| !(file->stats = (struct stat *)malloc(sizeof(struct stat))))
			exit(1);
		fill_file(file, child, args);
		if (get_stats(file->stats, file->path) < 0)
		{
			delete_file(file, 0);
			continue ;
		}
		if (!(node = ft_lstnew(file, sizeof(t_list))))
			exit(1);
		free(file);
		insert_node_to_list(&(args->files), node, args);
	}
}

static void	extract_dir(DIR *dir, t_args *args)
{
	t_list	*tmp_dirs;

	extract_child_to_list(args, dir);
	ft_lstdelnode(&(args->dirs), args->dirs, delete_dir);
	if (args->options.big_r)
	{
		if (args->files)
		{
			tmp_dirs = NULL;
			tmp_dirs = ft_lstmap(args->files, create_child_dir_node);
			merge_list_of_dirs(&(args->dirs), &tmp_dirs);
		}
		args->print_path = 1;
	}
	if (closedir(dir) == -1)
		str_perror(args->dirs->content);
	args->print_blocks = 1;
}

signed char	load_list_of_files(t_args *args)
{
	DIR		*dir;
	char	*tmp;

	if (args->files)
		return (1);
	if (args->dirs)
	{
		if (args->print_path)
			ft_printf("%s:\n", args->dirs->content);
		if ((dir = opendir(args->dirs->content)))
			extract_dir(dir, args);
		else
		{
			str_perror((tmp = ft_getfilename(args->dirs->content)));
			ft_lstdelnode(&(args->dirs), args->dirs, delete_dir);
			free(tmp);
		}
		return (1);
	}
	else
		return (0);
}
