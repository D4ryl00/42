/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:39:40 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/21 01:30:44 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

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
