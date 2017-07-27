/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:28:16 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 14:12:29 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

# define CLOSE 0
# define OPEN 1

typedef struct	s_door
{
	int			state;
}				t_door;

void			open_door(t_door *door);
void			close_door(t_door *door);
int				is_door_open(t_door *door);
int				is_door_close(t_door *door);

#endif
