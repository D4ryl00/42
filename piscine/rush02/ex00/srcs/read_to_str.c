/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:38:04 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/22 23:17:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/read_to_str.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_list	*ft_create_elem(char data)
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

void	ft_list_push_back(t_list **begin_list, char data)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (*begin_list)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
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
		free(current);
		current = next;
	}
	*begin_list = NULL;
}

void	list_to_str(t_list *list, char *result)
{
	while (list)
	{
		*result++ = list->data;
		list = list->next;
	}
}

char	*read_to_str(void)
{
	char	c;
	char	*result;
	int		count;
	t_list	*list;

	count = 0;
	while ((read(0, &c, 1)))
	{
		if (!count)
			list = ft_create_elem(c);
		else
			ft_list_push_back(&list, c);
		count++;
	}
	if (!(result = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (count)
	{
		list_to_str(list, result);
		ft_list_clear(&list);
	}
	result[count] = '\0';
	return (result);
}
