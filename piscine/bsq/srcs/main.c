/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:00:56 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/26 19:56:22 by gchojnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/print.h"
#include "../includes/board.h"
#include "../includes/resolve.h"
#include "../includes/import_matrix.h"
#include "../includes/free.h"

void	multi_map(int argc, char **argv)
{
	t_board	*board;
	t_coord	*done;
	int		i;

	i = 2;
	while (i < argc)
	{
		ft_putchar('\n');
		if (!(board = import_matrix(argc, argv, i)))
			ft_putnstr("map error\n", 10);
		else
		{
			if (!(done = resolve(board)))
				ft_putnstr("map error\n", 10);
			else
				print_result(board, done);
		}
		free_matrix(board);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_board	*board;
	t_coord	*done;

	if (!(board = import_matrix(argc, argv, 1)))
		ft_putnstr("map error\n", 10);
	else
	{
		if (!(done = resolve(board)))
			ft_putnstr("map error\n", 10);
		else
			print_result(board, done);
	}
	free_matrix(board);
	if (argc > 2)
		multi_map(argc, argv);
	return (0);
}
