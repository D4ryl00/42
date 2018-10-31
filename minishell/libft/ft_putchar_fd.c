/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:35:38 by rbarbero          #+#    #+#             */
/*   Updated: 2017/12/04 10:41:27 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(unsigned int c, int fd)
{
	unsigned char	*p;
	signed char		i;

	i = -1;
	c = ft_char_encode_utf8(c);
	p = (unsigned char *)&c;
	p += 3;
	while (++i < 4)
	{
		if (*p || i == 3)
			write(fd, p, 1);
		p--;
	}
}
