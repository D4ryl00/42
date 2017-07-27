/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 18:00:37 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/18 00:55:08 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char				*ft_strcpy(char *dest, char *src)
{
	char	*p;

	p = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (p);
}

void				add_arg(t_stock_par *tab, char **av, int i)
{
	tab[i].size_param = ft_strlen(av[i]);
	tab[i].str = av[i];
	tab[i].copy = malloc(sizeof(char) * (tab[i].size_param + 1));
	ft_strcpy(tab[i].copy, av[i]);
	tab[i].tab = ft_split_whitespaces(av[i]);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*tab;

	i = 0;
	tab = malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		add_arg(tab, av, i);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
