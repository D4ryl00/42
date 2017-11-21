/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:29:41 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/20 10:30:40 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin_list, void *content, size_t content_size)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (begin_list)
	{
		if (*begin_list)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = ft_lstnew(content, content_size);
		}
		else
			*begin_list = ft_lstnew(content, content_size);
	}
}
