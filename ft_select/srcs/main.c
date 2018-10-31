/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 10:58:32 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:44:45 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <termcap.h>
#include <stdlib.h>
#include <unistd.h>

int			print_usage(void)
{
	ft_putstr("usage: ft_select arg [arg ...]\n");
	return (0);
}

static int	commands(char buf, unsigned char *export)
{
	if (buf == 91)
	{
		if (read(0, &buf, 1) && buf == 'D')
			focus_left(g_args.list);
		if (buf == 'C')
			focus_right(g_args.list);
		if (buf == '3' && read(0, &buf, 1) && buf == '~')
			remove_focused();
	}
	else if (buf == ' ')
	{
		((t_item *)get_focused(g_args.list)->content)->selected ^= 1;
		focus_right(g_args.list);
	}
	else if (buf == 127)
		remove_focused();
	else if (buf == 10)
	{
		*export = 1;
		return (0);
	}
	return (1);
}

static void	main_loop(unsigned char *export)
{
	char	buf;

	while (g_args.list && (read(0, &buf, 1) == 1))
	{
		if (buf == 27 && is_esc_pressed(&buf, 1))
			break ;
		if (g_term.properties.activated)
			if (!commands(buf, export))
				break ;
		if (g_args.list)
			print();
	}
}

int			main(int argc, char **argv)
{
	unsigned char	export;

	if (argc < 2)
		return (print_usage());
	if (!(g_args.list = export_args(argv, argc)))
		return (1);
	export = 0;
	((t_item *)g_args.list->content)->focus = 1;
	g_args.col_sizes = NULL;
	set_signals();
	set_term_conf();
	main_loop(&export);
	restore_term();
	if (export)
		print_selected();
	return (0);
}
