/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 21:14:01 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/20 17:10:43 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_remove_elem(t_list **begin_list, t_list *elem, t_list *previous)
{
	if (previous == NULL)
		*begin_list = elem->next;
	else
		previous->next = elem->next;
	free(elem);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*next;
	t_list	*previous;

	current = *begin_list;
	previous = NULL;
	while (current)
	{
		next = current->next;
		if (!(*cmp)(current->data, data_ref))
			ft_remove_elem(begin_list, current, previous);
		else
			previous = current;
		current = next;
	}
}
