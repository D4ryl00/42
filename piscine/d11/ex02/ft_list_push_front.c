/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:46:13 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/19 15:00:18 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
