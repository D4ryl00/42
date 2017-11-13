/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:48:49 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 22:13:16 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku_solver.h"
#include "ft_checks.h"

int	ft_sudoku_solver(char **sudoku, int position)
{
	char	nbr;
	int		x;
	int		y;

	if (position == 81)
		return (1);
	x = position % 9;
	y = position / 9;
	nbr = '1';
	if (sudoku[x][y] != '.')
		return (ft_sudoku_solver(sudoku, position + 1));
	while (nbr <= ('0' + 9))
	{
		if (is_ok_line(sudoku, y, nbr)
				&& is_ok_row(sudoku, x, nbr)
				&& is_ok_block(sudoku, x, y, nbr))
		{
			sudoku[x][y] = nbr;
			if (ft_sudoku_solver(sudoku, position + 1))
				return (1);
		}
		nbr++;
	}
	sudoku[x][y] = '.';
	return (0);
}
