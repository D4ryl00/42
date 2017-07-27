/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchojnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:02:27 by gchojnac          #+#    #+#             */
/*   Updated: 2017/07/26 19:56:50 by gchojnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

typedef struct	s_board {
	char	**tab;
	int		width;
	int		height;
	char	char_full;
	char	char_obs;
	char	char_empty;
}				t_board;

typedef struct	s_int_board {
	int		**tab;
	int		width;
	int		height;
}				t_int_board;

typedef struct	s_coord {
	int		data;
	int		i_row;
	int		i_col;
}				t_coord;

#endif
