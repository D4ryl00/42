/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 09:44:10 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:45:23 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <termcap.h>
#include <unistd.h>

int		pchar(int c)
{
	write(g_term.properties.fd, &c, 1);
	return (c);
}

void	print(void)
{
	tputs(g_term.properties.clear_screen, g_term.properties.ws.ws_row, pchar);
	if (g_term.properties.activated)
	{
		print_header();
		print_commands();
		print_args();
	}
	else
		ft_putstr_fd("Please increase your terminal size !\n"
				, g_term.properties.fd);
}

void	print_selected(void)
{
	t_list			*p;
	unsigned char	first;

	first = 1;
	p = g_args.list;
	while (p)
	{
		if (((t_item *)p->content)->selected)
		{
			if (!first)
				ft_putchar(' ');
			ft_putstr(((t_item *)p->content)->name);
			first = 0;
		}
		p = p->next;
	}
}
