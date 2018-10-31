/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:57:10 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:10:14 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <termcap.h>

static void	display_item(t_item *item, int col)
{
	if (item->selected)
		tputs(g_term.properties.reverse_video, 1, pchar);
	if (item->focus)
		tputs(g_term.properties.underlining, 1, pchar);
	ft_dprintf(g_term.properties.fd, "%-*s", g_args.col_sizes[col], item->name);
	if (item->focus)
		tputs(g_term.properties.normal_text, 1, pchar);
	if (item->selected)
		tputs(g_term.properties.normal_video, 1, pchar);
}

static int	get_activated_col(void)
{
	int		actived_col;
	t_list	*p;

	p = g_args.list;
	actived_col = 0;
	while (p && !((t_item *)p->content)->focus)
	{
		actived_col++;
		if (actived_col == g_args.col_nbr)
			actived_col = 0;
		p = p->next;
	}
	return (actived_col);
}

static void	print_one(void)
{
	int		actived_col;
	int		i;
	t_list	*p;

	actived_col = get_activated_col();
	i = 0;
	p = g_args.list;
	while (p)
	{
		if (i == actived_col)
			display_item(p->content, i);
		if (++i == g_args.col_nbr)
		{
			ft_putchar_fd('\n', g_term.properties.fd);
			i = 0;
		}
		p = p->next;
	}
}

void		print_args(void)
{
	t_list	*p;
	int		i;

	p = g_args.list;
	i = 0;
	if (g_term.properties.ws.ws_col < g_args.max_col_size)
		print_one();
	else
	{
		while (p)
		{
			display_item(p->content, i);
			if (i < g_args.col_nbr - 1 && p->next)
				ft_putchar_fd('\t', g_term.properties.fd);
			if (++i == g_args.col_nbr)
			{
				ft_putchar_fd('\n', g_term.properties.fd);
				i = 0;
			}
			p = p->next;
		}
	}
}
