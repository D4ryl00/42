/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchojnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 12:49:51 by gchojnac          #+#    #+#             */
/*   Updated: 2017/07/26 19:59:51 by gchojnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/board.h"
#include "../includes/resolve.h"
#include "../includes/print.h"
#include <stdlib.h>

int			min_tab(t_int_board *res, int i_row, int i_col)
{
	int		a;
	int		b;
	int		c;
	int		temp;
	int		min;

	a = res->tab[i_row - 1][i_col - 1];
	b = res->tab[i_row][i_col - 1];
	c = res->tab[i_row - 1][i_col];
	temp = (a < b) ? a : b;
	min = (c < temp) ? c : temp;
	return (min + 1);
}

int			populate_res(t_board *board, t_int_board *res)
{
	int		i_row;
	int		i_col;

	i_row = -1;
	i_col = -1;
	while (++i_col < res->width)
		res->tab[0][i_col] = 0;
	while (++i_row < res->height)
		res->tab[i_row][0] = 0;
	i_row = 0;
	while (++i_row < res->height)
	{
		i_col = 0;
		while (++i_col < res->width)
		{
			if (board->tab[i_row - 1][i_col - 1] == board->char_empty)
				res->tab[i_row][i_col] = min_tab(res, i_row, i_col);
			else if (board->tab[i_row - 1][i_col - 1] == board->char_obs)
				res->tab[i_row][i_col] = 0;
			else
				return (0);
		}
	}
	return (1);
}

t_coord		*max_on_board(t_int_board *res)
{
	int			r;
	int			c;
	t_coord		*to_return;

	r = res->height;
	if (!(to_return = malloc(sizeof(t_coord))))
		return (0);
	to_return->data = -1;
	while (--r > 0)
	{
		c = res->width;
		while (--c > 0)
		{
			if (to_return->data <= res->tab[r][c])
			{
				to_return->data = res->tab[r][c];
				to_return->i_row = r - 1;
				to_return->i_col = c - 1;
			}
		}
	}
	return (to_return);
}

t_coord		*resolve(t_board *board)
{
	t_int_board		res;
	t_coord			*max_entry;
	int				i;

	res.width = board->width + 1;
	res.height = board->height + 1;
	i = 0;
	if (!(res.tab = malloc(sizeof(res.tab) * res.height)))
		return (0);
	while (i < res.height)
		if (!(res.tab[i++] = malloc(sizeof(*(res.tab)) * res.width)))
			return (0);
	if (populate_res(board, &res) == 0)
		return (0);
	max_entry = max_on_board(&res);
	while (--i >= 0)
		free(res.tab[i]);
	free(res.tab);
	return (max_entry);
}
