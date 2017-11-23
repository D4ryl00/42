/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:25:01 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/23 02:00:44 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int		count_tetri(const char *input)
{
	int nbr;

	nbr = 1;
	if (!input)
		return (0);
	while (*input)
	{
		if (*input == '\n')
			nbr++;
		input++;
	}
	return (nbr);
}

static t_coord	locate_scheme(t_tetri *tetri, const char *input)
{
	char	i;
	t_coord	*min;
	t_coord	*max;

	if (!(min = (t_coord *)malloc(sizeof(t_coord)))
			|| !(max = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	i = -1;
	min->y = 4;
	min->x = 4;
	max->y = 0;
	max->x = 0;
	while (input[++i] && i < 20)
	{
		if (input[i] == '#')
		{
			min->y = min->y > i / 4 ? i / 4 : min->y;
			min->x = min->x > i % 4 ? i % 4 : min->x;
			max->y = max->y < i / 4 ? i / 4 : max->y;
			max->x = max->x < i % 4 ? i % 4 : max->x;
		}
	}
	tetri->row = max->y - min->y + 1;
	tetri->col = max->x - min->x + 1;
	return (min);
}

static char		**parse_tetri(t_tetri *tetri, char **input)
{
	t_coord	*start;
	char	index;
	char	i;

	start = locate_scheme(tetri, *input);
	index = start->y * 4  + start->x;
	if (!(tetri->scheme = (char **)malloc(sizeof(char *) * tetri->row)))
			return (NULL);
	i = -1;
	while (++i < tetri->row)
		if (!(tetri->scheme[i] = (char *)malloc(tetri->col)))
				return (NULL);
	i = 0;
	while ((i / 4) * min_y + i < tetri->row * 4 + tetri->col)

t_tetri		*parse(char *input, char *nb_tetri)
{
	t_tetri	**tetris;
	int		i;

	*nb_tetri = count_tetri(input);
	if (!(tetris = (t_tetri **)malloc(nb_tetri *)))
		return (NULL);
	i = -1;
	while (++i < nb_tetri)
	{
		if (!(tetris[i] = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		parse_tetri(tetris[i], &input);
	}
	return (tetris);
}
