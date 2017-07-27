/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 00:31:24 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/09 16:45:06 by adupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_symb(int x, int y, int xmax, int ymax)
{
	if (y == 1)
	{
		if (x == 1)
			ft_putchar('o');
		else if (x == xmax)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else if (y == ymax && y != 1)
	{
		if (x == 1)
			ft_putchar('o');
		else if (x == xmax)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (x == 1 || x == xmax)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	xmax;
	int	ymax;

	xmax = x;
	ymax = y;
	y = 1;
	while (y <= ymax)
	{
		x = 1;
		while (x <= xmax)
		{
			ft_print_symb(x, y, xmax, ymax);
			if (x == xmax)
				ft_putchar('\n');
			x++;
		}
		y++;
	}
}
