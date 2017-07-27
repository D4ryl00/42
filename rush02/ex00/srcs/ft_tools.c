/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 22:39:21 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/22 22:40:07 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_tools.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*p;

	p = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (p);
}

void	ft_putnbr(int nb)
{
	int power;
	int tmp;

	tmp = nb;
	power = 1;
	while (tmp /= 10)
		power *= 10;
	if (nb < 0)
		ft_putchar('-');
	else
		nb = -nb;
	while (power)
	{
		ft_putchar(-((nb / power) % 10) + '0');
		power /= 10;
	}
}

void	ft_print(char *name, int x, int y)
{
	ft_putchar('[');
	ft_putstr(name);
	ft_putchar(']');
	ft_putstr(" [");
	ft_putnbr(x);
	ft_putchar(']');
	ft_putstr(" [");
	ft_putnbr(y);
	ft_putchar(']');
}
