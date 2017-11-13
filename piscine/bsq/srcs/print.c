/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 20:29:18 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/25 23:27:02 by gchojnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/board.h"
#include "../includes/print.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnstr(char *str, int n)
{
	write(1, str, n);
}

void	print_matrix(t_board *board)
{
	int i;

	i = 0;
	while (i < board->height)
	{
		write(1, board->tab[i++], board->width);
		ft_putchar('\n');
	}
}

void	put_row_square(char c, int nb)
{
	char	str[nb];
	int		i;

	i = 0;
	while (i < nb)
		str[i++] = c;
	ft_putnstr(str, nb);
}

void	print_result(t_board *board, t_coord *corner_rb)
{
	t_coord		corner_lt;
	int			row;

	corner_lt.i_col = corner_rb->i_col - corner_rb->data + 1;
	corner_lt.i_row = corner_rb->i_row - corner_rb->data + 1;
	row = -1;
	while (++row < board->height)
	{
		if (row >= corner_lt.i_row && row <= corner_rb->i_row)
		{
			ft_putnstr(board->tab[row], corner_lt.i_col);
			put_row_square(board->char_full, corner_rb->data);
			ft_putnstr(board->tab[row] + corner_rb->i_col + 1
					, board->width - corner_rb->i_col - 1);
		}
		else
			ft_putnstr(board->tab[row], board->width);
		ft_putchar('\n');
	}
}
