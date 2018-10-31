/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 21:23:02 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:13:42 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termcap.h>

void	exit_properly(int sig)
{
	restore_term();
	if (g_args.col_sizes)
		free(g_args.col_sizes);
	exit(sig);
}

void	get_winsize(int sig)
{
	(void)sig;
	if (ioctl(g_term.properties.fd, TIOCGWINSZ, &(g_term.properties.ws)) == -1)
		exit_properly(1);
	if (g_args.col_sizes)
	{
		free(g_args.col_sizes);
		g_args.col_sizes = NULL;
	}
	g_args.col_nbr = get_col_nbr(g_args.list);
	if (!(g_args.col_sizes = get_col_sizes(g_args.list, g_args.col_nbr)))
		exit_properly(1);
	g_args.max_col_size = get_max_col_size();
	if ((g_term.properties.ws.ws_row < HEADER_HEIGHT + 1)
			|| (g_term.properties.ws.ws_col
			< get_max_each_col(g_args.col_sizes, g_args.col_nbr))
			|| (g_term.properties.ws.ws_col < HEADER_WIDTH))
		g_term.properties.activated = 0;
	else
		g_term.properties.activated = 1;
	print();
}

void	stop(int sig)
{
	char	c;

	(void)sig;
	tputs(g_term.properties.disable_full_screen, 1, pchar);
	tputs(g_term.properties.visible_cursor, 1, pchar);
	tcsetattr(0, TCSANOW, &(g_term.save));
	signal(SIGTSTP, SIG_DFL);
	c = g_term.current.c_cc[VSUSP];
	ioctl(g_term.properties.fd, TIOCSTI, &c);
}

void	resume(int sig)
{
	(void)sig;
	signal(SIGTSTP, stop);
	tcsetattr(0, TCSANOW, &(g_term.current));
	tputs(g_term.properties.enable_full_screen, 1, pchar);
	tputs(g_term.properties.invisible_cursor, 1, pchar);
	get_winsize(0);
	print();
}

void	set_signals(void)
{
	signal(SIGHUP, exit_properly);
	signal(SIGINT, exit_properly);
	signal(SIGPIPE, exit_properly);
	signal(SIGALRM, exit_properly);
	signal(SIGTERM, exit_properly);
	signal(SIGXCPU, exit_properly);
	signal(SIGXFSZ, exit_properly);
	signal(SIGVTALRM, exit_properly);
	signal(SIGPROF, exit_properly);
	signal(SIGUSR1, exit_properly);
	signal(SIGUSR2, exit_properly);
	signal(SIGWINCH, get_winsize);
	signal(SIGTSTP, stop);
	signal(SIGCONT, resume);
}
