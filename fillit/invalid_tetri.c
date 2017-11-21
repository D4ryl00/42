/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:09:22 by sderet            #+#    #+#             */
/*   Updated: 2017/11/20 19:49:25 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static char	size_check(char *tet)
{
	int a;
	int b;
	int c;

	a = 0;
	c = 0;
	while (tet[a] != '\0')
	{
		b = 0;
		while (b < 4)
		{
			if (tet[a + b] != '#' && tet[a + b] != '.')
				return (err_std);
			b++;
		}
		c++;
		if (tet[a + b] != '\n' || c > 4 || (tet[a + b + 1] == '\n' && c != 4))
			return (err_std);
		if (tet[a + b + 1] == '\n')
			c = 0;
		a += (tet[a + b + 1] == '\n' ? b + 2 : b + 1);
	}
	if (c != 4)
		return (err_std);
	return (0);
}

static char	nb_blocks_check(char *tet)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (tet[a] != '\0')
	{
		if (tet[a] == '#')
			b++;
		else if (tet[a] == '\n' && (tet[a + 1] == '\n' || tet[a + 1] == '\0'))
		{
			if (b != 4)
				return (err_std);
			b = 0;
		}
		a++;
	}
	return (0);
}

static char	char_check(char *tet)
{
	int a;

	a = 0;
	while (tet[a] != '\0')
	{
		if (tet[a] != '.' && tet[a] != '#' && tet[a] != '\n')
			return (err_std);
		a++;
	}
	return (0);
}

static char	valid_tetri_check(char *tet)
{
	int		a;
	char	**tab;

	a = 0;
	tab = ft_strsplit(tet, '\n');
}

char		check_error(char *tetriminos)
{
	int	(*tests[4])(char *tetriminos);
	int	a;

	a = 0;
	test[0] = &size_check;
	test[1] = &nb_blocks_check;
	test[2] = &char_check;
	test[3] = &valid_tetri_check;
	while (a <= 3)
	{
		if (test(tetriminos) == 1)
			return (1);
		a++;
	}
	return (0);
}
