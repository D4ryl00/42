/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:15:06 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/24 16:10:43 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	free_memory(t_tetri **tetris, t_grid *resolve, char *input
		, unsigned char nb_tetri)
{
	int	i;
	int	j;

	i = -1;
	while (++i < nb_tetri)
	{
		j = -1;
		while (++j < tetris[i]->row)
			free(tetris[i]->scheme[j]);
		free(tetris[i]->scheme);
		free(tetris[i]);
	}
	free(tetris);
	i = -1;
	while (++i < GRID_SIZE)
		free(resolve->tab[i]);
	free(resolve->tab);
	free(resolve);
	free(input);
}

int		main(int argc, char **argv)
{
	char			*input;
	unsigned char	nb_tetri;
	t_tetri			**tetris;
	t_grid			*result;

	if (argc != 2)
		return (print_usage());
	if (!(input = ft_read(argv[1]))
			|| !check_error(input)
			|| !(tetris = parse(input, &nb_tetri))
			|| !(result = resolve(tetris, nb_tetri)))
		return (print_error());
	print_result(result);
	free_memory(tetris, result, input, nb_tetri);
	return (0);
}
