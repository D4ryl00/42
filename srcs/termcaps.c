/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 06:49:24 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:16:49 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <stdlib.h>
#include <termcap.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	init_termcaps(void)
{
	char	*term_type;
	int		success;

	if (isatty(1))
		g_term.properties.fd = 1;
	else
	{
		if ((g_term.properties.fd = open(ttyname(0), O_RDWR)) == -1)
		{
			ft_putstr("Could not open the file descriptor.\n");
			exit(1);
		}
	}
	if (!(term_type = getenv("TERM")))
	{
		ft_putstr("Specify a terminal type with \
`setenv TERM <yourtype>'.\n");
		exit(1);
	}
	if ((success = tgetent(NULL, term_type) < 1))
	{
		ft_putstr_fd("Error: could not load termcaps.\n", 2);
		exit(1);
	}
}

static void	minimal_properties(void)
{
	if (!(g_term.properties.enable_full_screen = tgetstr("ti", NULL)))
	{
		ft_putstr_fd("your terminal don't support fullscreen mode\n", 2);
		exit_properly(1);
	}
	g_term.properties.disable_full_screen = tgetstr("te", NULL);
	tputs(g_term.properties.enable_full_screen, 1, pchar);
	if (!(g_term.properties.cursor_move = tgetstr("cm", NULL)))
		exit_properly(2);
	g_term.properties.clear_screen = tgetstr("cl", NULL);
	g_term.properties.reverse_video = tgetstr("mr", NULL);
	g_term.properties.normal_video = tgetstr("me", NULL);
	g_term.properties.underlining = tgetstr("us", NULL);
	g_term.properties.normal_text = tgetstr("ue", NULL);
	g_term.properties.invisible_cursor = tgetstr("vi", NULL);
	g_term.properties.visible_cursor = tgetstr("ve", NULL);
	tputs(g_term.properties.invisible_cursor, 1, pchar);
}

void		set_term_conf(void)
{
	char	*temp;

	init_termcaps();
	if (tcgetattr(0, &(g_term.save))
			|| tcgetattr(0, &(g_term.current)))
		exit(1);
	ospeed = g_term.current.c_ospeed;
	temp = tgetstr("pc", NULL);
	PC = temp ? *temp : 0;
	free(temp);
	g_term.current.c_lflag &= ~(ICANON | ECHO);
	g_term.current.c_cc[VMIN] = 1;
	g_term.current.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &(g_term.current)))
		exit(1);
	minimal_properties();
	get_winsize(0);
}

void		restore_term(void)
{
	tputs(g_term.properties.visible_cursor, 1, pchar);
	tputs(g_term.properties.disable_full_screen, 1, pchar);
	if (g_term.properties.fd != 1)
		close(g_term.properties.fd);
	tcsetattr(0, TCSANOW, &(g_term.save));
}

int			is_esc_pressed(char *buf, int size)
{
	g_term.current.c_cc[VMIN] = 0;
	g_term.current.c_cc[VTIME] = 1;
	tcsetattr(0, TCSANOW, &(g_term.current));
	if (!read(0, buf, size))
		return (1);
	g_term.current.c_cc[VMIN] = 1;
	g_term.current.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &(g_term.current));
	return (0);
}
