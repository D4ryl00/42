/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:09:22 by sderet            #+#    #+#             */
/*   Updated: 2017/11/27 13:45:36 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

/*
**	Checks if every line in the file is 4 characters long, or 1 character
**	long if it is the space between two tetriminos.
**	Returns 1 if the file works, 0 else.
*/

static unsigned char	size_check(char *tet)
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
				return (0);
			b++;
		}
		c++;
		if (tet[a + b] != '\n' || c > 4 || (tet[a + b + 1] == '\n' && c != 4))
			return (0);
		if (tet[a + b + 1] == '\n')
			c = 0;
		a += (tet[a + b + 1] == '\n' ? b + 2 : b + 1);
	}
	if (c != 4)
		return (0);
	return (1);
}

/*
**	Checks if every character in the file is either a ., a # or a \n.
**	Checks if each tetriminos has 4 #. If not, returns 0.
*/

static unsigned char	nb_blocks_check(char *tet)
{
	int a;
	int b;
	int c;

	a = -1;
	b = 0;
	c = 0;
	while (tet[++a] != '\0')
	{
		if (tet[a] != '.' && tet[a] != '#' && tet[a] != '\n')
			return (0);
		if (tet[a] == '\n')
			c++;
		if (tet[a] == '#')
			b++;
		else if (tet[a] == '\n' && (tet[a + 1] == '\n' || tet[a + 1] == '\0'))
		{
			if (b != 4)
				return (0);
			b = 0;
		}
	}
	if (c < 4)
		return (0);
	return (1);
}

/*
**	Modify bvar if un hash is adjacent with an other
*/

static void				check_adj(int *bvar, char *input, int *i)
{
	if ((*i) - 5 >= (*bvar >> 24) / 4 + ((*bvar >> 24) / 4)
			* 20 && input[*i - 5] == '#')
		*bvar += 0x100;
	if ((*i) - 1 >= (*bvar >> 24) / 4 + ((*bvar >> 24) / 4)
			* 20 && input[*i - 1] == '#')
		*bvar += 0x100;
	if ((*i) + 1 < (*bvar >> 24) / 4 + ((*bvar >> 24) / 4)
			* 20 + 20 && input[*i + 1] == '#')
		*bvar += 0x100;
	if ((*i) + 5 < (*bvar >> 24) / 4 + ((*bvar >> 24) / 4)
			* 20 + 20 && input[*i + 5] == '#')
		*bvar += 0x100;
}

/*
** Checks if each # in each tetriminos has at least one adjacent #.
** If not, returns 1.
** unsigned int bvar;
** Bitwise operations on bvar
** 00000000 00000000 00000000 00000000
**    1        2        3        4
** Explanation of each segment
** 1: number of hash in input
** 2: number of hash adjacent with 2 other in input
** 3: number of adjacent hash in one tetri
** 4: index
*/

static unsigned char	valid_tetri_check(char *input)
{
	int	bvar;
	int i;

	bvar = 0;
	i = 0;
	while (input[i])
	{
		while (input[i] && input[i] != '#')
			i++;
		while (input[i] && input[i] == '#')
		{
			bvar &= 0xffff00ff;
			check_adj(&bvar, input, &i);
			if (!((bvar & 0xff00) >> 8))
				return (0);
			bvar += ((bvar & 0xff00) >> 8) > 1 && ((bvar & 0xff0000) >> 16)
				< (bvar >> 24) / 4 + 1 ? 0x10000 : 0;
			if (((bvar & 0xff0000) >> 16) < (bvar >> 24) / 4)
				return (0);
			bvar += 0x1000000;
			i++;
		}
	}
	return ((bvar & 0xff0000) >> 16 == (bvar >> 24) / 4 ? 1 : 0);
}

/*
**	Uses the other functions in the file to check for any error.
**	If any error is detected, returns 0.
*/

unsigned char			check_error(char *tetriminos)
{
	unsigned char	(*test[3])(char *tetriminos);
	unsigned char	i;

	i = 0;
	test[0] = &size_check;
	test[1] = &nb_blocks_check;
	test[2] = &valid_tetri_check;
	while (i < 3)
	{
		if (test[i](tetriminos) == 0)
			return (0);
		i++;
	}
	return (1);
}
