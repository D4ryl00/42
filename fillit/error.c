/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:35:18 by sderet            #+#    #+#             */
/*   Updated: 2017/11/21 17:12:50 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	err_argnbr(void)
{
	ft_putendl("usage: ./fillit source_file");
}

char	err_std(void)
{
	ft_putendl("error");
	return (1);
}

int		valid_line_check(char **tab, int a, int c)
{
	int b;
	int d;
	int e;

	b = 0;
	d = a + c;
	while (tab[d][b] != '\0')
	{
		if (tab[d][b] == '#')
			if ((c != 3 ? tab[d + 1][b] != '#' : 1) &&
				(c != 0 ? tab[d - 1][b] != '#' : 1) &&
				(b != 0 ? tab[d][b - 1] != '#' : 1) &&
				tab[d][b + 1] != '#')
				return (1);
		b++;
	}
	return (0);
}

int		last_check(char **tab)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = 0;
	while (tab[a] != 0)
	{
		c = 0;
		d = 0;
		while (c < 4)
		{
			b = 0;
			while (tab[a + c][b] != '\0')
			{
				if (tab[a + c][b] == '#')
					d++;
				if (tab[a + c][b] == '#' && d <= 3)
					if ((c != 3 ? tab[a + c + 1][b] != '#' : 1) &&
							tab[a + c][b + 1] != '#')
						return (1);
				b++;
			}
			c++;
		}
		a += 4;
	}
	return (0);
}
