/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:33:59 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/20 19:43:45 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FILLIT_H
# define FILLIT_H

typedef struct	s_tetri
{
	char	*schem;
	char	row;
	char	col;
}				t_tetri;

int				print_usage(void);
int				print_error(void);
#endif
