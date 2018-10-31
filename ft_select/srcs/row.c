/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:41:26 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:11:53 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <stdlib.h>

int	get_max_col_size(void)
{
	int	max;
	int	i;

	max = 0;
	i = -1;
	while (++i < g_args.col_nbr)
	{
		max += g_args.col_sizes[i];
		if (i + 1 != g_args.col_nbr)
			max += g_args.col_sizes[i] % 8 ?
				(g_args.col_sizes[i] / 8 + 1) * 8 - g_args.col_sizes[i] : 8;
	}
	return (max);
}

int	get_max_each_col(int *arr, int nbr)
{
	int	max;
	int	i;

	max = 0;
	i = -1;
	while (++i < nbr)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

int	get_col_nbr(t_list *list)
{
	int		col_nbr;
	int		height;
	int		list_size;

	height = g_term.properties.ws.ws_row - HEADER_HEIGHT;
	if (height < 1)
		height = 1;
	list_size = ft_lstsize(list);
	col_nbr = 1;
	if (list_size > height)
		col_nbr = list_size / height + (list_size % height ? 1 : 0);
	g_args.line_nbr = list_size / col_nbr;
	return (col_nbr);
}

int	*get_col_sizes(t_list *args, int nbr)
{
	int	*dest;
	int	i;
	int	size;

	if (!(dest = (int *)malloc(sizeof(int) * (nbr))))
	{
		ft_putstr_fd("get_col_sizes: malloc error\n", 2);
		exit_properly(1);
	}
	i = -1;
	while (++i < nbr)
		dest[i] = 0;
	i = 0;
	while (args)
	{
		size = ft_strlen(((t_item *)args->content)->name);
		if (size > dest[i])
			dest[i] = size;
		if (++i == nbr)
			i = 0;
		args = args->next;
	}
	return (dest);
}
