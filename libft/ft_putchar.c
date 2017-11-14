/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:24:31 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/14 23:17:51 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(int c)
{
	char	*p;

	p = (char *)&c;
	if (c > 0xff)
	{
		write(1, p + 3, 1);
		write(1, p + 2, 1);
	}
	if (c > 0x7f)
		write(1, p + 1, 1);
	write(1, p, 1);
}
