/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:14:58 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/16 11:38:36 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	while (*alst)
	{
		lst = *alst;
		*alst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = NULL;
	}
}
