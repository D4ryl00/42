/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:33:59 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/21 19:26:09 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_tetri
{
	char	*scheme;
	char	row;
	char	col;
}				t_tetri;

int				print_usage(void);
int				print_error(void);

void			err_argnbr(void);
char			err_std(void);
int				valid_line_check(char **tab, int a, int c);
int				last_check(char**tab);
char			check_error(char *tetriminos);
t_tetri			*parse(char *input, char *nb_tetri);
char			*resolve(t_tetri **tetris, int nb_tetri);
void			print_result(char **result);

#endif
