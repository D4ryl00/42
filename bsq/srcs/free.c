/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:51:25 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/26 19:55:37 by gchojnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/board.h"

void	free_matrix(t_board *board)
{
	int i;

	if (board)
	{
		i = -1;
		while (++i < board->height)
			if (board->tab[i])
				free(board->tab[i]);
		if (board->tab)
			free(board->tab);
		free(board);
	}
}
