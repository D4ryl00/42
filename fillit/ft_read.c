/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:19:19 by sderet            #+#    #+#             */
/*   Updated: 2017/11/21 18:57:04 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

char	**ft_read(char **filename)
{
	int		fd;
	char	str[550];
	int		test;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (test != 0)
		test = read(fd, str, 21);
	if (close(fd) == -1)
		return (0);
	return (1);
}
