/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_u_perm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:52:29 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/04 13:55:47 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

char	get_file_ur_perm(struct stat *stats)
{
	if (stats->st_mode & 00400)
		return ('r');
	else
		return ('-');
}

char	get_file_uw_perm(struct stat *stats)
{
	if (stats->st_mode & 00200)
		return ('w');
	else
		return ('-');
}

char	get_file_ux_perm(struct stat *stats)
{
	if (stats->st_mode & 00100)
	{
		if (stats->st_mode & 04000)
			return ('s');
		return ('x');
	}
	else
	{
		if (stats->st_mode & 04000)
			return ('S');
		return ('-');
	}
}
