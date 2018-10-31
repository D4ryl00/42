/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:52:04 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 07:22:40 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

quad_t	get_total_blocks(t_list *files)
{
	quad_t	total;

	total = 0;
	while (files)
	{
		total += ((t_file *)files->content)->stats->st_blocks;
		files = files->next;
	}
	return (total);
}

void	fill_max_width(int *max_width, t_args *args)
{
	max_width[0] = get_max_width_hd(args->files);
	max_width[1] = args->options.g ? 0 : get_max_width_uname(args->files);
	max_width[2] = get_max_width_gname(args->files);
	max_width[3] = get_max_width_major(args->files);
	max_width[4] = get_max_width_size(args->files);
}

void	printl_print1(t_file *file, t_args *args, int *max_width)
{
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c %*d ", get_file_type(file->stats)
			, get_file_ur_perm(file->stats), get_file_uw_perm(file->stats)
			, get_file_ux_perm(file->stats), get_file_gr_perm(file->stats)
			, get_file_gw_perm(file->stats), get_file_gx_perm(file->stats)
			, get_file_or_perm(file->stats), get_file_ow_perm(file->stats)
			, get_file_ox_perm(file->stats), get_file_ext_attr(file->path)
			, max_width[0], file->stats->st_nlink);
	if (!args->options.g && get_uname(file->stats))
		ft_printf("%-*s  ", max_width[1], get_uname(file->stats));
	else if (!args->options.g)
		ft_printf("%-*d  ", max_width[1], file->stats->st_uid);
	if (get_gname(file->stats))
		ft_printf("%-*s  ", max_width[2], get_gname(file->stats));
	else
		ft_printf("%-*d  ", max_width[2], file->stats->st_gid);
	if (S_ISBLK(file->stats->st_mode) || S_ISCHR(file->stats->st_mode))
		ft_printf("%*d, %*d ", max_width[3], major(file->stats->st_rdev),
				max_width[4], minor(file->stats->st_rdev));
	else
		ft_printf("%*c %*lld ", max_width[3] + 1, ' '
				, max_width[4], file->stats->st_size);
}

void	printl_print2(t_file *file, t_args *args)
{
	char			*time;
	char			buf[257];
	ssize_t			size;

	ft_printf("%s ", time = get_date(args));
	free(time);
	put_color(((t_file *)args->files->content)->stats, &(args->options));
	ft_putstr(file->name);
	end_color(&(args->options));
	if ((size = readlink(file->path, buf, 256)) != -1)
	{
		buf[size] = '\0';
		ft_printf(" -> %s", buf);
	}
	ft_putchar('\n');
}
