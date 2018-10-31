/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:48:41 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 06:29:40 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <time.h>

static void	parse_recent_date(char *dest, char *date)
{
	ft_strncpy(dest, &(date[4]), 7);
	dest[7] = ' ';
	ft_strncpy((&dest[8]), &(date[20]), 4);
	dest[12] = '\0';
}

char		*get_date(t_args *args)
{
	time_t	file_time;
	time_t	now;
	char	*date;
	char	*res;

	now = time(NULL);
	if (args->options.u)
		file_time = ((t_file *)args->files->content)->stats->st_atime;
	else
		file_time = ((t_file *)args->files->content)->stats->st_mtime;
	if (!(date = ctime(&file_time)))
		exit(1);
	if (!(res = (char *)malloc(sizeof(char) * 13)))
		exit(1);
	if (ft_absolute(now - file_time) >= ((365 / 2) * 86400))
		parse_recent_date(res, date);
	else
	{
		ft_strncpy(res, &(date[4]), 12);
		res[12] = '\0';
	}
	return (res);
}
