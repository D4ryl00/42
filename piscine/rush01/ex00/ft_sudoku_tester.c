/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:48:33 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 22:12:28 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku_tester.h"
#include "ft_checks.h"

int	ft_sudoku_tester(char **sudoku, int position)
{
	char	nbr;
	int		total;

	nbr = '0';
	total = 0;
	if (position == 81)
		return (1);
	while (++nbr <= '9')
	{
		if (sudoku[position % 9][position / 9] != '.')
		{
			total = ft_sudoku_tester(sudoku, position + 1);
			break ;
		}
		if (is_ok_line(sudoku, position / 9, nbr)
				&& is_ok_row(sudoku, position % 9, nbr)
				&& is_ok_block(sudoku, position % 9, position / 9, nbr))
		{
			sudoku[position % 9][position / 9] = nbr;
			total += ft_sudoku_tester(sudoku, position + 1);
		}
		sudoku[position % 9][position / 9] = '.';
	}
	return (total);
}
