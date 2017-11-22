/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:21:29 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/22 15:12:26 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	can_put(t_tetri *tetri, char **tab, int y, int x)
{
	int a;
	int b;

	a = 0;
	while(a < tetri->col)
	{
		b = 0;
		while (b < tetri->row)
		{
			if (tetri->scheme[a][b] != '.' && tab[y + a][x + b]  != '.')
				return (1);
			b++;
		}
		a++;
	}
	return (0);
}

static char	**clear_tab(char **tab, char c)
{
	int a;
	int b;

	a = -1;
	if (c == 0)
	{
		while (++a < 105)
		{
			b = -1;
			while (++b < 105)
				tab[a][b] = '.';
		}
	}
	else
	{
		while (++a < 105)
		{
			b = -1;
			while (++b < 105)
				if (tab[a][b] == c)
					tab[a][b] = '.';
		}
	}
	return (tab);
}

static char	**tetri_put(t_tetri *tetri, char **tab, int y, int x)
{
	int a;
	int b;

	a = 0;
	while (a < tetri->col)
	{
		b = 0;
		while (b < tetri->row)
		{
			if (tetri->scheme[a][b] != '.')
				tab[y + a][x + b] = tetri->scheme[a][b];
			b++;
		}
		a++;
	}
	return (tab);
}

static char	**try_size(t_tetri **tetris, int nb_tetri, int size)
{
	int a;
	int b;
	int index_tetri;

	a = 0;
	index_tetri = 0;
	while (a < size && index_tetri < nb_tetri)
	{
		b = 0;
		while (b < size && index_tetri < nb_tetri)
		{
			if (can_put(tetris[index_tetri], tab, a, b) == 0)
			{
				tab = tetri_put(tetris[index_tetri], tab, a, b);
				index_tetri++;
			}
			b++;
		}
		a++;
	}
	return (tab);
}

char		*resolve(t_tetri **tetris, int nb_tetri)
{
	int		min_size;
	char	tab_final[105][105];
	char	**ideal_tab;

	min_size = 4;
}
