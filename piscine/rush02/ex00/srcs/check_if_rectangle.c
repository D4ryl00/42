/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_rectangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:06:03 by kjalloul          #+#    #+#             */
/*   Updated: 2017/07/23 01:15:44 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_if_rectangle.h"
#include "../includes/read_to_str.h"

void			edit_struct(int x, int is_rectangle, t_rect_size *rush)
{
	rush->y++;
	rush->x = x;
	rush->is_rectangle = is_rectangle;
}

int				check_if_rect_extans(int i, char *str, t_rect_size *rush)
{
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		rush->is_rectangle = 0;
	return (i);
}

void			check_if_rectangle(char *str, t_rect_size *rush)
{
	int i;
	int length[2];

	i = 0;
	length[1] = 0;
	i = check_if_rect_extans(i, str, rush);
	if (rush->is_rectangle == 0)
		return ;
	length[0] = i;
	while (str[i + 1] != '\0')
	{
		(str[i++] == '\n') ? rush->y++ : 0;
		while (str[i] != '\n' && str[i] != '\0')
		{
			i++;
			length[1]++;
		}
		if (length[1] != length[0])
		{
			rush->is_rectangle = 0;
			return ;
		}
		length[1] = 0;
	}
	edit_struct(length[0], 1, rush);
}

t_rect_size		*check_and_count(char *str)
{
	t_rect_size *rush;

	if (!(rush = malloc(sizeof(*rush))))
		return (NULL);
	if (*str == '\0')
	{
		rush->is_rectangle = 0;
		return (rush);
	}
	rush->x = 0;
	rush->y = 0;
	rush->is_rectangle = 1;
	check_if_rectangle(str, rush);
	return (rush);
}
