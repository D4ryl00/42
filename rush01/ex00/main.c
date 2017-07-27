/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 12:52:59 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 22:45:24 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_sudoku_solver.h"
#include "ft_sudoku_tester.h"
#include "ft_checks.h"

void	ft_print(char **sudoku)
{
	int x;
	int y;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			write(1, &sudoku[x][y], 1);
			if (x != 8)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

char	fill_tab(char **sudoku, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[j + 1][i] == '.'
					|| (is_ok_line(sudoku, j, argv[j + 1][i])
					&& is_ok_row(sudoku, i, argv[j + 1][i])
					&& is_ok_block(sudoku, i, j, argv[j + 1][i])))
				sudoku[i][j] = argv[j + 1][i];
			else
				return (-1);
			j++;
		}
		i++;
	}
	return (**sudoku);
}

int		ft_error(long long int possibility)
{
	write(1, "Error\n", 6);
	return (possibility);
}

int		main(int argc, char **argv)
{
	char			**sudoku;
	long long int	i;

	sudoku = 0;
	if (argc != 10)
		return (ft_error(0));
	i = 1;
	while (i < argc)
		if (!check_line(argv[i++]))
			return (ft_error(0));
	sudoku = malloc(sizeof(char*) * 9);
	i = 0;
	while (i < 9)
		sudoku[i++] = malloc(sizeof(char) * 9);
	if (fill_tab(sudoku, argv) < 0)
		return (ft_error(0));
	if ((i = ft_sudoku_tester(sudoku, 0)) > 1)
		return (ft_error(i));
	ft_sudoku_solver(sudoku, 0);
	ft_print(sudoku);
	i = 0;
	while (i < 9)
		free(sudoku[i++]);
	free(sudoku);
	return (0);
}
