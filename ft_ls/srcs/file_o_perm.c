/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_o_perm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:56:48 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/04 13:57:23 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

char	get_file_or_perm(struct stat *stats)
{
	if (stats->st_mode & 00004)
		return ('r');
	else
		return ('-');
}

char	get_file_ow_perm(struct stat *stats)
{
	if (stats->st_mode & 00002)
		return ('w');
	else
		return ('-');
}

char	get_file_ox_perm(struct stat *stats)
{
	if (stats->st_mode & 00001)
	{
		if (stats->st_mode & 01000)
			return ('t');
		return ('x');
	}
	else
	{
		if (stats->st_mode & 01000)
			return ('T');
		return ('-');
	}
}
