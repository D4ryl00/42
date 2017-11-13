/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 01:55:16 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/09 14:30:28 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbchar(char c, int nb)
{
	while (nb-- > 0)
		ft_putchar(c);
}

void	ft_count_width(int level, int *nbrasterisk, int *width)
{
	int	nbrline;
	int	i;

	nbrline = level + 2;
	i = 0;
	while (i < nbrline)
	{
		*width = *nbrasterisk / 2;
		*nbrasterisk += 2;
		i++;
	}
}

void	ft_print_door(int i, int nbrline, int door)
{
	if (i == nbrline - (door / 2 + 1) && door > 3)
	{
		ft_putnbchar('|', door - 2);
		ft_putchar('$');
		ft_putchar('|');
	}
	else
		ft_putnbchar('|', door);
}

void	ft_level(int size, int level, int *nbrasterisk, int *width)
{
	int	nbrline;
	int	i;
	int	door;

	nbrline = level + 2;
	door = level % 2 ? level : level - 1;
	i = 0;
	while (i < nbrline)
	{
		ft_putnbchar(' ', *width - *nbrasterisk / 2);
		ft_putchar('/');
		ft_putnbchar('*', (*nbrasterisk - door) / 2);
		if (level == size && i >= nbrline - door)
			ft_print_door(i, nbrline, door);
		else
			ft_putnbchar('*', door);
		ft_putnbchar('*', (*nbrasterisk - door) / 2);
		ft_putchar('\\');
		ft_putchar('\n');
		*nbrasterisk += 2;
		i++;
	}
	door = (level - 1) % 2 * 2;
}

void	sastantua(int size)
{
	int	nbrasterisk;
	int	step;
	int	level;
	int width;
	int test;

	test = 1;
	while (test >= 0)
	{
		nbrasterisk = 1;
		step = 4;
		level = 1;
		while (level <= size)
		{
			test ? ft_count_width(level, &nbrasterisk, &width)
				: ft_level(size, level, &nbrasterisk, &width);
			nbrasterisk += step;
			step += (level - 1) % 2 * 2;
			level++;
		}
		test--;
	}
}
