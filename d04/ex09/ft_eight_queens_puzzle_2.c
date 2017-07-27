/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:39:22 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/13 08:14:11 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_diag(int board[8], int x, int y)
{
	int row;
	int line;

	row = x;
	line = y;
	while (row >= 0 && line >= 0)
	{
		if (board[row--] == line--)
			return (0);
	}
	row = x;
	line = y;
	while (row < 8 && line < 8)
	{
		if (board[row++] == line++)
			return (0);
	}
	return (1);
}

int		ft_diag2(int board[8], int x, int y)
{
	int row;
	int line;

	row = x;
	line = y;
	while (row < 8 && line >= 0)
	{
		if (board[row++] == line--)
			return (0);
	}
	row = x;
	line = y;
	while (row >= 0 && line < 8)
	{
		if (board[row--] == line++)
			return (0);
	}
	return (1);
}

int		ft_line(int board[8], int line)
{
	int row;

	row = 0;
	while (row < 8)
	{
		if (board[row] == line)
			return (0);
		row++;
	}
	return (1);
}

int		ft_recursive_eight_queens_puzzle_2(int bd[8], int qn)
{
	int pos;
	int final;
	int i;

	pos = 0;
	final = 0;
	while (pos < 8)
	{
		if (ft_diag(bd, qn, pos) && ft_diag2(bd, qn, pos) && ft_line(bd, pos))
		{
			bd[qn] = pos;
			if (qn == 7)
			{
				i = 0;
				while (i < 8)
					ft_putchar(bd[i++] + 1 + '0');
				ft_putchar('\n');
				final += 1;
			}
			final += ft_recursive_eight_queens_puzzle_2(bd, qn + 1);
		}
		bd[qn] = -1;
		pos++;
	}
	return (final);
}

int		ft_eight_queens_puzzle_2(void)
{
	int	i;
	int	board[8];

	i = 0;
	while (i < 8)
	{
		board[i] = -1;
		i++;
	}
	return (ft_recursive_eight_queens_puzzle_2(board, 0));
}
