/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:37:29 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 07:45:10 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

void	insert_node_to_list(t_list **list, t_list *node, t_args *args)
{
	t_list	*(*ifct)(t_list **, t_list *, int (*cmp)(t_list *, t_list *));

	if (args->options.f)
		ft_lstaddback(list, node);
	else
	{
		ifct = ft_lstsortedinsert;
		if (!args->options.t)
			args->cmp = sort_by_name;
		if (args->options.r)
			ifct = ft_lstrsortedinsert;
		ifct(list, node, args->cmp);
	}
}

t_list	*create_child_dir_node(t_list *node)
{
	t_list	*tmp;
	t_file	*file;

	file = node->content;
	if (S_ISDIR(file->stats->st_mode)
			&& !ft_strequ(file->name, ".") && !ft_strequ(file->name, ".."))
	{
		if (!(tmp = ft_lstnew(file->path, sizeof(char)
						* (ft_strlen(file->path) + 1))))
			exit(1);
		return (tmp);
	}
	return (NULL);
}
