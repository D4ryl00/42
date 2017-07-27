/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:54:16 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/26 18:34:53 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*tmp;

	if ((tmp = malloc(sizeof(t_list))) == 0)
		return (0);
	if (tmp)
	{
		tmp->data = data;
		tmp->next = NULL;
	}
	return (tmp);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (*begin_list)
	{
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = tmp;
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_list_clear(t_list **begin_list)
{
	t_list	*current;
	t_list	*next;

	current = *begin_list;
	while (current)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	*begin_list = NULL;
}
