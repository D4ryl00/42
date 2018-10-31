/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:29:55 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/13 16:56:15 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <stdlib.h>

t_list	*export_args(char **av, int ac)
{
	t_list	*list;
	t_list	*new;
	int		i;

	i = ac;
	list = NULL;
	while (--i)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list)))
				|| !(new->content = (t_item *)malloc(sizeof(t_item))))
		{
			if (list)
				ft_lstdel(&list, delete_item);
			ft_putstr_fd("export_args: malloc error\n", 2);
			return (NULL);
		}
		((t_item *)new->content)->name = ft_strdup(av[i]);
		((t_item *)new->content)->selected = 0;
		((t_item *)new->content)->focus = 0;
		new->next = list;
		list = new;
	}
	return (list);
}

void	delete_item(void *content, size_t size)
{
	(void)size;
	if (((t_item *)content)->name)
		free(((t_item *)content)->name);
	free(content);
}
