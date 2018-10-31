/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printl_max_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 06:35:30 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 07:23:49 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>

int	get_max_width_hd(t_list *files)
{
	int	max;
	int	size;

	max = 0;
	while (files)
	{
		size = ft_nbrlen(((t_file *)files->content)->stats->st_nlink);
		if (size > max)
			max = size;
		files = files->next;
	}
	return (max);
}

int	get_max_width_uname(t_list *files)
{
	int				max;
	struct passwd	*pw;
	int				size;

	max = 0;
	while (files)
	{
		if (!(pw = getpwuid(((t_file *)files->content)->stats->st_uid)))
			size = ft_nbrlen(((t_file *)files->content)->stats->st_uid);
		else
			size = ft_strlen(pw->pw_name);
		if (size > max)
			max = size;
		files = files->next;
	}
	return (max);
}

int	get_max_width_gname(t_list *files)
{
	int				max;
	struct group	*group;
	int				size;

	max = 0;
	while (files)
	{
		if (!(group = getgrgid(((t_file *)files->content)->stats->st_gid)))
			size = ft_nbrlen(((t_file *)files->content)->stats->st_gid);
		else
			size = ft_strlen(group->gr_name);
		if (size > max)
			max = size;
		files = files->next;
	}
	return (max);
}

int	get_max_width_major(t_list *files)
{
	int	max;
	int	size;

	max = 0;
	while (files)
	{
		if (S_ISBLK(((t_file *)files->content)->stats->st_mode)
				|| S_ISCHR(((t_file *)files->content)->stats->st_mode))
			size = ft_nbrlen(major(((t_file *)files->content)->stats->st_rdev));
		if (size > max)
			max = size;
		files = files->next;
	}
	return (max);
}

int	get_max_width_size(t_list *files)
{
	int	max;
	int	size;

	max = 0;
	while (files)
	{
		if (S_ISBLK(((t_file *)files->content)->stats->st_mode)
				|| S_ISCHR(((t_file *)files->content)->stats->st_mode))
			size = ft_nbrlen(minor(((t_file *)files->content)->stats->st_rdev));
		else
			size = ft_nbrlen(((t_file *)files->content)->stats->st_size);
		if (size > max)
			max = size;
		files = files->next;
	}
	return (max);
}
