/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:15:06 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/22 15:10:47 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*input;
	char	nb_tetri;
	t_tetri	**tetri;
	char	*result;

	if (argc != 2)
		return (print_usage());
	if (!(input = ft_read(argv[1]))
			|| !check_error(input)
			|| !(tetri = parse(input, &nb_tetri))
			|| !(result = resolve(tetri, nb_tetri)))
		return (print_error());
	free_memory(tetri, result, input, nb_tetri);
	return (0);
}
