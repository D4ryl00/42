/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 11:56:53 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 14:05:39 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_door.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = OPEN;
}

void	close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = CLOSE;
}

int		is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	return (door->state == OPEN);
}

int		is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	return (door->state == CLOSE);
}
