/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 09:40:10 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/27 16:23:50 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		value_base(char *base)
{
	int res;

	res = 0;
	while (*base++)
		res++;
	return (res);
}

char	value_digit(int position, char *base)
{
	while (position-- > 0)
		base++;
	return (*base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	v_base;

	v_base = value_base(base);
	if (!nbr)
		return ;
	ft_putnbr_base(nbr / v_base, base);
	ft_putchar(value_digit(nbr % v_base, base));
}
