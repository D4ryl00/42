/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:38:46 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/04 13:12:10 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

signed char	get_args_stats(struct stat *stats, char *name, t_options *options)
{
	signed char	ret;

	if (options->big_h)
	{
		ret = stat(name, stats);
		if (!ret)
			return (0);
	}
	ret = lstat(name, stats);
	if (ret < 0)
	{
		str_perror(name);
		return (-1);
	}
	return (0);
}

signed char	get_stats(struct stat *stats, char *name)
{
	signed char	ret;

	ret = lstat(name, stats);
	if (ret < 0)
	{
		str_perror(name);
		return (-1);
	}
	return (0);
}
