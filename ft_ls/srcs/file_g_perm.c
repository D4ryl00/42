/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_g_perm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:54:51 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/04 13:55:38 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

char	get_file_gr_perm(struct stat *stats)
{
	if (stats->st_mode & 00040)
		return ('r');
	else
		return ('-');
}

char	get_file_gw_perm(struct stat *stats)
{
	if (stats->st_mode & 00020)
		return ('w');
	else
		return ('-');
}

char	get_file_gx_perm(struct stat *stats)
{
	if (stats->st_mode & 00010)
	{
		if (stats->st_mode & 02000)
			return ('s');
		return ('x');
	}
	else
	{
		if (stats->st_mode & 02000)
			return ('S');
		return ('-');
	}
}
