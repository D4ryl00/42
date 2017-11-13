/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 19:58:35 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/26 01:01:30 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list)
	{
		if (--nbr == 0)
			return (begin_list);
		begin_list = begin_list->next ? begin_list->next : 0;
	}
	return (0);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*start;
	t_list	*end;
	void	*tmp;
	int		size;

	start = begin_list;
	end = begin_list;
	if (begin_list)
	{
		size = 1;
		while (end->next)
		{
			end = end->next;
			size++;
		}
		while (start != end && end->next != start)
		{
			tmp = end->data;
			end->data = start->data;
			start->data = tmp;
			start = start->next;
			end = ft_list_at(begin_list, --size);
		}
	}
}
