/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:33:59 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/25 10:41:32 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define GRID_SIZE 104

typedef struct	s_tetri
{
	char			**scheme;
	unsigned char	row;
	unsigned char	col;
	char			letter;
}				t_tetri;

typedef struct	s_grid
{
	unsigned char	size;
	char			**tab;
	int				index_tetri;
}				t_grid;

typedef struct	s_coord
{
	unsigned char	x;
	unsigned char	y;
}				t_coord;

unsigned char	print_usage(void);
unsigned char	print_error(void);

char			*ft_read(char *filename);
unsigned char	check_error(char *tetriminos);
t_tetri			**parse(const char *input, unsigned char *nb_tetri);
t_grid			*resolve(t_tetri **tetris, unsigned char nb_tetri);
void			print_result(t_grid *result);

#endif
