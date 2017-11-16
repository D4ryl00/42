/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:20:23 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/16 22:00:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	free_memory(t_list *lst)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		free(lst->content);
		free(lst);
		lst = next;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*p;
	t_list	*tmp;
	t_list	*prev;
	int		is_first;

	new = NULL;
	is_first = 1;
	while (lst)
	{
		tmp = f(lst);
		if (!(p = ft_lstnew(tmp->content, tmp->content_size)))
		{
			free_memory(new);
			return (NULL);
		}
		if (is_first)
			new = p;
		else
			prev->next = p;
		is_first = 0;
		prev = p;
		lst = lst->next;
	}
	return (new);
}
