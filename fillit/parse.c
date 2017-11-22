/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:25:01 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/22 16:19:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int	count_tetri(const char *input)
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

static void	compute_size(t_tetri *tetri, const char *input)
{
	int	width;
	int	height;
	int	flag;

	width = 0;
	height = 0;
	while (*input && i < 4)
	{
		flag = 1;
		while(*input && input != '\n')
		{
			if (*input == '#')
			{
				width++;
				height += flag;
				flag = 0;
				i++;
			}
		}
	}
	tetri->row = width;
	tetri->col = height;
}

static void	parse_tetri(t_tetri *tetri, char **input)
{
	compute_size(tetri, *input);
	if (!(tetri->scheme = (char **)malloc(tetri->row * tetri->col)


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
