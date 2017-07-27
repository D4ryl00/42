/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_rectangle.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 21:00:14 by kjalloul          #+#    #+#             */
/*   Updated: 2017/07/23 01:13:47 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_IF_RECTANGLE_H
# define CHECK_IF_RECTANGLE_H

# include <stdlib.h>

typedef struct	s_rect_size
{
	int x;
	int y;
	int is_rectangle;
}				t_rect_size;

t_rect_size		*check_and_count(char *str);
void			check_if_rectangle(char *str, t_rect_size *rush);
void			ft_copy(char *str, char *str2, int biggest);
void			edit_struct(int x, int is_rectangle, t_rect_size *rush);
int				check_if_rect_extans(int i, char *str, t_rect_size *rush);

#endif
