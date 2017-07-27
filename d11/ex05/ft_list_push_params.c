/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:33:12 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/20 14:48:31 by rbarbero         ###   ########.fr       */
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

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;

	i = -1;
	list = 0;
	while (++i < ac)
		ft_list_push_front(&list, *av++);
	return (list);
}
