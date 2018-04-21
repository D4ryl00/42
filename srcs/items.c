/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 07:02:46 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:06:34 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <stdlib.h>

int		is_focused(t_list *node, void *data)
{
	(void)data;
	if (((t_item *)node->content)->focus)
		return (1);
	return (0);
}

t_list	*get_focused(t_list *list)
{
	while (list)
	{
		if (((t_item *)list->content)->focus)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	remove_focused(void)
{
	t_list	*next;

	if (!(next = get_focused(g_args.list)->next))
		next = g_args.list;
	ft_lstdelif(&(g_args.list), NULL, is_focused, delete_item);
	if (next)
		((t_item *)next->content)->focus = 1;
}

void	focus_right(t_list *list)
{
	t_list	*focused;

	if ((focused = get_focused(list)))
	{
		((t_item *)focused->content)->focus = 0;
		if (focused->next)
			((t_item *)focused->next->content)->focus = 1;
		else
			((t_item *)list->content)->focus = 1;
	}
}

void	focus_left(t_list *list)
{
	t_list	*focused;
	t_list	*p;

	if ((focused = get_focused(list)))
	{
		((t_item *)focused->content)->focus = 0;
		p = list;
		if (focused == list)
		{
			while (p->next)
				p = p->next;
			((t_item *)p->content)->focus = 1;
		}
		else
		{
			while (p->next != focused)
				p = p->next;
			((t_item *)p->content)->focus = 1;
		}
	}
}
