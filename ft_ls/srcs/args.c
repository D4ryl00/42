/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 09:17:42 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 06:32:36 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/stat.h>

static void		add_arg_to_list(char *name, t_args *args)
{
	t_list		*node;
	t_file		*file;
	struct stat	*stats;

	if (!(stats = (struct stat *)malloc(sizeof(struct stat))))
		exit(1);
	if (get_args_stats(stats, name, &(args->options)) < 0)
	{
		free(stats);
		return ;
	}
	if (!(file = (t_file *)malloc(sizeof(t_file))))
		exit(1);
	file->name = ft_strdup(name);
	file->path = ft_strdup(name);
	file->stats = stats;
	if (!(node = ft_lstnew(file, sizeof(t_file))))
		exit(1);
	free(file);
	insert_node_to_list(&(args->files), node, args);
}

static int		node_is_dir(t_list *node, void *data)
{
	(void)data;
	if (S_ISDIR(((t_file *)node->content)->stats->st_mode))
		return (1);
	return (0);
}

static t_list	*create_args_dir_node(t_list *node)
{
	t_list	*tmp;
	t_file	*file;

	file = node->content;
	if (S_ISDIR(file->stats->st_mode))
	{
		if (!(tmp = ft_lstnew(file->path, sizeof(char)
						* (ft_strlen(file->path) + 1))))
			exit(1);
		return (tmp);
	}
	return (NULL);
}

static void		get_args(t_args *args, int argc, char **argv, int *ac)
{
	if (*ac < argc)
	{
		while (*ac < argc)
		{
			add_arg_to_list(argv[*ac], args);
			(*ac)++;
		}
	}
	else
		add_arg_to_list(".", args);
	if (!args->options.d)
	{
		args->dirs = ft_lstmap(args->files, create_args_dir_node);
		ft_lstdelif(&(args->files), NULL, node_is_dir, delete_file);
	}
}

void			parse_argline(t_args *args, int argc, char **argv)
{
	int	ac;

	ac = 0;
	get_options(args, argc, argv, &ac);
	get_args(args, argc, argv, &ac);
	if ((ft_lstsize(args->files) && ft_lstsize(args->dirs) > 0)
			|| ft_lstsize(args->dirs) > 1)
		args->print_path = 1;
}
