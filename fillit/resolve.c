/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:21:29 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/24 15:57:03 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

/*
** Return 1 if the tetriminos can be put on the grid at the position.
** Else return 0.
*/

static unsigned char	can_put(t_tetri *tetri, t_grid *grid, t_coord spot)
{
	t_coord	pos;

	if (tetri->col + spot.x >= grid->size || tetri->row + spot.y >= grid->size)
		return (0);
	pos.y = -1;
	while (++pos.y < tetri->row)
	{
		pos.x = -1;
		while (++pos.x < tetri->col)
			if (tetri->scheme[pos.y][pos.x] != '.'
					&& grid->tab[spot.y + pos.y][spot.x + pos.x] != '.')
				return (0);
	}
	return (1);
}

/*
** If c is null, put dot in the whole grid.
** Else erase c char in the grid and put dot instead.
** Return the grid.
*/

static char				**clear_tab(t_grid *grid, t_tetri *tetri, t_coord *spot)
{
	t_coord pos;

	pos.y = -1;
	if (tetri == 0)
	{
		while (++pos.y < grid->size)
		{
			pos.x = -1;
			while (++pos.x < grid->size)
				grid->tab[pos.y][pos.x] = '.';
		}
	}
	else
	{
		while (++pos.y < tetri->row)
		{
			pos.x = -1;
			while (++pos.x < tetri->col)
				if (tetri->scheme[pos.y][pos.x] != '.')
					grid->tab[spot->y + pos.y][spot->x + pos.x] = '.';
		}
	}
	return (grid->tab);
}

/*
** write the tetriminos into the grid and return the grid.
*/

static char				**tetri_put(t_tetri *tetri, t_grid *grid, t_coord spot)
{
	t_coord	pos;

	pos.y = -1;
	while (++pos.y < tetri->row)
	{
		pos.x = -1;
		while (++pos.x < tetri->col)
			if (tetri->scheme[pos.y][pos.x] != '.')
				grid->tab[spot.y + pos.y][spot.x + pos.x] = tetri->letter;
	}
	return (grid->tab);
}

/*
**	Tries to put all the tetriminos in the grid for a given size.
**	Uses backtracking to test all solutions.
**	Returns 0 if unsuccessful, 1 if it works.
*/

static int				try_size(t_tetri **tetris, t_grid *grid, int nb_tetri)
{
	t_coord	spot;

	spot.y = -1;
	if (grid->index_tetri == nb_tetri)
		return (1);
	while (++spot.y < grid->size && grid->index_tetri < nb_tetri)
	{
		spot.x = -1;
		while (++spot.x < grid->size && grid->index_tetri < nb_tetri)
		{
			if (can_put(tetris[grid->index_tetri], grid, spot))
			{
				grid->tab = tetri_put(tetris[grid->index_tetri], grid, spot);
				grid->index_tetri++;
				if (try_size(tetris, grid, nb_tetri))
					return (1);
				else
				{
					grid->index_tetri--;
					clear_tab(grid, tetris[grid->index_tetri], &spot);
				}
			}
		}
	}
	return (0);
}

/*
**	Resolves the grid by calling try_size with increasing sizes until
**	it works. Returns a pointer to the completed grid.
*/

t_grid					*resolve(t_tetri **tetris, unsigned char nb_tetri)
{
	t_grid			*grid;
	unsigned char	i;

	if (!(grid = (t_grid*)malloc(sizeof(t_grid))))
		return (NULL);
	if (!(grid->tab = (char**)malloc(sizeof(char*) * GRID_SIZE)))
		return (NULL);
	i = -1;
	while (++i < GRID_SIZE)
		if (!(grid->tab[i] = (char*)malloc(sizeof(char) * GRID_SIZE)))
			return (NULL);
	grid->size = 2;
	grid->index_tetri = 0;
	clear_tab(grid, 0, 0);
	while (try_size(tetris, grid, nb_tetri) == 0)
	{
		grid->index_tetri = 0;
		clear_tab(grid, 0, 0);
		grid->size++;
	}
	return (grid);
}
