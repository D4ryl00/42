/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:58:46 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/27 14:30:08 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert_rest(t_list **begin_list
		, void *data, int (*cmp)())
{
	t_list	*prev;
	t_list	*next;

	prev = *begin_list;
	next = (*begin_list)->next ? (*begin_list)->next : 0;
	while (prev)
	{
		if (!next)
		{
			prev->next = ft_create_elem(data);
			prev->next->next = 0;
			return ;
		}
		else if ((*cmp)(data, next->data) <= 0)
		{
			prev->next = ft_create_elem(data);
			prev->next->next = next;
			return ;
		}
		prev = prev->next;
		next = next->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*next;

	if (data)
	{
		if (!*begin_list || (*cmp)(data, (*begin_list)->data) < 0)
		{
			next = *begin_list;
			*begin_list = ft_create_elem(data);
			(*begin_list)->next = next;
			return ;
		}
		else
			ft_sorted_list_insert_rest(begin_list, data, cmp);
	}
}
