/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:49:28 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 07:20:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	print1(t_args *args)
{
	while (args->files)
	{
		put_color(((t_file *)args->files->content)->stats, &(args->options));
		ft_putstr(((t_file *)args->files->content)->name);
		end_color(&(args->options));
		ft_putchar('\n');
		ft_lstdelnode(&(args->files), args->files, delete_file);
	}
}

void		printl(t_args *args)
{
	t_file			*file;
	int				max_width[5];
	quad_t			blocks;

	fill_max_width(max_width, args);
	blocks = get_total_blocks(args->files);
	if (args->print_blocks && args->files)
		ft_printf("total %d\n", blocks);
	while (args->files)
	{
		file = (t_file *)args->files->content;
		printl_print1(file, args, max_width);
		printl_print2(file, args);
		ft_lstdelnode(&(args->files), args->files, delete_file);
	}
}

static void	copy_files_to_array(t_arr_args *ar, t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		ar->names[i] = ((t_file *)list->content)->name;
		ar->stats[i++] = ((t_file *)list->content)->stats;
		list = list->next;
	}
}

void		print_default(t_args *args)
{
	t_arr_args	ar;

	ar.nbr = ft_lstsize(args->files);
	if (!(ar.names = (char **)malloc(sizeof(char *) * ar.nbr)))
		exit(1);
	if (!(ar.stats = (struct stat **)malloc(sizeof(struct stat *)
					* ar.nbr)))
		exit(1);
	ar.options = &(args->options);
	copy_files_to_array(&ar, args->files);
	print_row(&ar);
	free(ar.names);
	free(ar.stats);
	ft_lstdel(&(args->files), delete_file);
}

void		print_args(t_args *args)
{
	if (args->options.l)
		printl(args);
	else if (args->options.one | !isatty(1))
		print1(args);
	else
		print_default(args);
	if (args->dirs)
		ft_putchar('\n');
}
