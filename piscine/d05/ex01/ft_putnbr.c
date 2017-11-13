/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 22:14:06 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/10 23:50:52 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
