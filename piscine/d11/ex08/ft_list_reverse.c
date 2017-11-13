/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:24:23 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/25 19:43:30 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next;
	t_list	*current;
	t_list	*previous;

	if (*begin_list)
	{
		previous = 0;
		next = (*begin_list)->next ? (*begin_list)->next : 0;
		current = *begin_list;
		while (current)
		{
			current->next = previous;
			previous = current;
			current = next;
			next = next ? next->next : 0;
		}
		*begin_list = previous;
	}
}
