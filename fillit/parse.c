/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:25:01 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/24 16:05:55 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

/*
** Count the number of tetriminos in the input and return the result.
*/

static unsigned char	count_tetri(const char *input)
{
	unsigned char	nbr;

	nbr = 0;
	if (!input)
		return (0);
	while (*input)
	{
		if (*input == '\n' && (*(input + 1) == '\n' || !*(input + 1)))
			nbr++;
		input++;
	}
	return (nbr);
}

/*
** Set the width and the height, in the tetri array, of each rectangle
** containing each tetriminos given in the input.
** It's returns the coordinates of the upper left corner of this rectangle.
*/

static t_coord			*locate_scheme(t_tetri *tetri, const char *input)
{
	unsigned char	i;
	t_coord			*min;
	t_coord			*max;

	if (!(min = (t_coord *)malloc(sizeof(t_coord)))
			|| !(max = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	i = -1;
	min->y = 5;
	min->x = 5;
	max->y = 0;
	max->x = 0;
	while (input[++i] && i < 20)
		if (input[i] == '#')
		{
			min->y = min->y > i / 5 ? i / 5 : min->y;
			min->x = min->x > i % 5 ? i % 5 : min->x;
			max->y = max->y < i / 5 ? i / 5 : max->y;
			max->x = max->x < i % 5 ? i % 5 : max->x;
		}
	tetri->row = max->y - min->y + 1;
	tetri->col = max->x - min->x + 1;
	free(max);
	return (min);
}

/*
** Copy each titriminos given in the input in the tetri array.
** Return the new 2D array contening the tetriminos.
*/

static char				**copy_tetri(t_tetri *tetri, const char *input)
{
	t_coord			*start;
	unsigned char	index;
	unsigned char	i;
	unsigned char	j;

	start = locate_scheme(tetri, input);
	index = start->y * 5 + start->x;
	free(start);
	if (!(tetri->scheme = (char **)malloc(sizeof(char *) * tetri->row)))
		return (NULL);
	i = -1;
	while (++i < tetri->row)
	{
		if (!(tetri->scheme[i] = (char *)malloc(tetri->col + 1)))
			return (NULL);
		j = -1;
		while (++j < tetri->col)
			tetri->scheme[i][j] = input[index + i * 5 + j];
		tetri->scheme[i][j] = '\0';
	}
	return (tetri->scheme);
}

t_tetri					**parse(const char *input, unsigned char *nb_tetri)
{
	t_tetri			**tetris;
	unsigned char	i;

	*nb_tetri = count_tetri(input);
	if (!(tetris = (t_tetri **)malloc(sizeof(t_tetri *) * *nb_tetri)))
		return (NULL);
	i = -1;
	while (++i < *nb_tetri)
	{
		if (!(tetris[i] = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		if (!(copy_tetri(tetris[i], &input[i * 20 + i])))
			return (NULL);
		tetris[i]->letter = 'A' + i;
	}
	return (tetris);
}
