/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 06:36:05 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 06:29:05 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>

static void	put_color2(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putstr("\x1B[34m");
	else if (S_ISLNK(mode))
		ft_putstr("\x1B[35m");
	else if (S_ISSOCK(mode))
		ft_putstr("\x1B[32m");
	else if (S_ISFIFO(mode))
		ft_putstr("\x1B[33m");
	else if (mode & 00100 || mode & 00010 || mode & 00001)
		ft_putstr("\x1B[31m");
	else if (S_ISBLK(mode))
		ft_putstr("\x1B[34;46m");
	else if (S_ISCHR(mode))
		ft_putstr("\x1B[34;43m");
}

void		put_color(struct stat *stats, t_options *options)
{
	mode_t	mode;

	mode = stats->st_mode;
	if (options->big_g && isatty(1))
	{
		if (S_ISDIR(mode) && mode & 00002 && mode & 01000)
			ft_putstr("\x1B[30;42m");
		else if (S_ISDIR(mode) && mode & 00002)
			ft_putstr("\x1B[30;43m");
		else if (mode & 04000 && (mode & 00100 || mode & 00010 || mode & 00001))
			ft_putstr("\x1B[30;41m");
		else if (mode & 02000 && (mode & 00100 || mode & 00010 || mode & 00001))
			ft_putstr("\x1B[30;46m");
		else
			put_color2(mode);
	}
}

void		end_color(t_options *options)
{
	if (options->big_g && isatty(1))
		ft_putstr("\x1B[0m");
}
