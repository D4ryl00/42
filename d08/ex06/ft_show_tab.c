/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:42:00 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/18 00:56:19 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
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

void	ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i++]);
		ft_putchar('\n');
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	while (par->str != 0)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size_param);
		ft_putchar('\n');
		ft_print_words_tables(par->tab);
		par++;
	}
}
