/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:28:20 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/21 01:01:20 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

void	ft_list_swap(t_list **begin_list
		, t_list **prev, t_list **current, t_list **next)
{
	if (*prev)
		(*prev)->next = *next;
	else
		*begin_list = *next;
	(*current)->next = (*next)->next;
	(*next)->next = *current;
	*prev = *next;
	*next = (*current)->next;
}

void	ft_list_sort_r(t_list **begin_list, int (*cmp)(), int size)
{
	int		i;
	t_list	*current;
	t_list	*previous;
	t_list	*next;

	if (size < 2)
		return ;
	i = -1;
	current = *begin_list;
	next = current->next;
	previous = 0;
	while (++i < size - 1)
	{
		if ((*cmp)(current->data, next->data) > 0)
			ft_list_swap(begin_list, &previous, &current, &next);
		else
		{
			previous = current;
			current = next;
			next = next->next;
		}
	}
	ft_list_sort_r(begin_list, cmp, size - 1);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int size;

	size = ft_list_size(*begin_list);
	ft_list_sort_r(begin_list, cmp, size);
}
