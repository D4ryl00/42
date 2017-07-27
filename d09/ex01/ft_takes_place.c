/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:45:37 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 16:32:59 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	decade;
	int	copy;

	decade = 1;
	copy = nb;
	if (nb < 0)
		ft_putchar('-');
	else
		nb = -nb;
	while (copy /= 10)
		decade *= 10;
	while (decade * 10 > 1)
	{
		ft_putchar(-(nb / decade % 10) + '0');
		decade /= 10;
	}
}

int		ft_hour(int hour)
{
	hour %= 24;
	if (hour == 0)
		hour += 12;
	if (hour > 12)
		hour %= 12;
	return (hour);
}

char	*ft_am_pm(int hour)
{
	hour %= 24;
	if (hour < 12)
		return ("A.M.");
	return ("P.M.");
}

void	ft_takes_place(int hour)
{
	write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
	ft_putnbr(ft_hour(hour));
	write(1, ".00 ", 4);
	write(1, ft_am_pm(hour), 4);
	write(1, " AND ", 5);
	ft_putnbr(ft_hour(hour + 1));
	write(1, ".00 ", 4);
	write(1, ft_am_pm(hour + 1), 4);
	write(1, "\n", 1);
}
