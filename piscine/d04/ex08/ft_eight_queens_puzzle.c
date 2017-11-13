/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:57:14 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/12 15:37:02 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_safe_diagonal(int board[8], int x, int y)
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

int	ft_safe_diagonal2(int board[8], int x, int y)
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

int	ft_safe_line(int board[8], int line)
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

int	ft_recursive_eight_queens_puzzle(int board[8], int queen)
{
	int position;
	int final;

	position = 0;
	final = 0;
	while (position < 8)
	{
		if (ft_safe_diagonal(board, queen, position)
				&& ft_safe_diagonal2(board, queen, position)
				&& ft_safe_line(board, position))
		{
			board[queen] = position;
			if (queen == 7)
			{
				final += 1;
			}
			final += ft_recursive_eight_queens_puzzle(board, queen + 1);
		}
		board[queen] = -1;
		position++;
	}
	return (final);
}

int	ft_eight_queens_puzzle(void)
{
	int	i;
	int	board[8];

	i = 0;
	while (i < 8)
	{
		board[i] = -1;
		i++;
	}
	return (ft_recursive_eight_queens_puzzle(board, 0));
}
