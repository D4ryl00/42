/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:53:32 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/19 21:10:02 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *)
		, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (!(*cmp)(begin_list->data, data_ref))
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
