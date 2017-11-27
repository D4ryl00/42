/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:19:19 by sderet            #+#    #+#             */
/*   Updated: 2017/11/24 10:07:48 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_read(char *filename)
{
	int		fd;
	char	*str;
	char	tmp[4096];
	int		test;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((test = read(fd, tmp, 4096)))
		;
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		return (NULL);
	str[ft_strlen(tmp)] = '\0';
	ft_strcpy(str, tmp);
	if (close(fd) == -1)
		return (0);
	return (str);
}
