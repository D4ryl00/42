/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:35:32 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/27 14:34:39 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_aux(t_list **begin_list1, t_list *begin_list2
		, t_list *cur1, t_list **prev1)
{
	if (cur1 == *begin_list1)
	{
		*begin_list1 = begin_list2;
		(*begin_list1)->next = cur1;
	}
	else
	{
		(*prev1)->next = begin_list2;
		(*prev1)->next->next = cur1;
		*prev1 = (*prev1)->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1
		, t_list *begin_list2, int (*cmp)())
{
	t_list	*prev1;
	t_list	*cur1;
	t_list	*next2;

	if (*begin_list1 && begin_list2)
	{
		prev1 = 0;
		cur1 = *begin_list1;
		next2 = begin_list2->next;
		while (begin_list2)
		{
			if (!cur1 || (*cmp)(begin_list2->data, cur1->data) <= 0)
			{
				ft_sorted_aux(begin_list1, begin_list2, cur1, &prev1);
				begin_list2 = next2;
				if (next2)
					next2 = next2->next ? next2->next : 0;
			}
			else
			{
				prev1 = cur1;
				cur1 = cur1->next;
			}
		}
	}
}
