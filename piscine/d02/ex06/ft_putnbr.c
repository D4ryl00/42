/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 01:51:52 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/06 14:33:25 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int power;
	int tmp;

	tmp = nb;
	power = 1;
	while (tmp /= 10)
	{
		power *= 10;
	}
	if (nb < 0)
	{
		ft_putchar('-');
	}
	else
	{
		nb = -nb;
	}
	while (power)
	{
		ft_putchar(-((nb / power) % 10) + '0');
		power /= 10;
	}
}
