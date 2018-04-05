/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:17:40 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 07:25:56 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/stat.h>

static int	get_max_width(char **names, int nbr)
{
	int	max_width;
	int	size;
	int	i;

	i = -1;
	max_width = 0;
	while (++i < nbr)
		if ((size = ft_strlen(names[i])) > max_width)
			max_width = size;
	return (max_width);
}

static void	print_space(t_wspos *wspos, t_arr_args *ar, t_wscfg *wscfg)
{
	int		tab_nbr;
	int		item_size;

	if (ar->options->big_g)
	{
		item_size = ft_strlen(ar->names[wspos->col_pos
				* wscfg->row_nbr + wspos->row_pos]);
		tab_nbr = -1;
		while (++tab_nbr < wscfg->col_size - item_size)
			ft_putchar(' ');
	}
	else
	{
		item_size = ft_strlen(ar->names[wspos->col_pos
				* wscfg->row_nbr + wspos->row_pos]);
		tab_nbr = (wscfg->col_size - item_size) % 8 ? (wscfg->col_size
				- item_size) / 8 + 1 : (wscfg->col_size - item_size) / 8;
		while (tab_nbr--)
			ft_putchar('\t');
	}
}

static void	p_row(t_arr_args *ar, t_wscfg *wscfg)
{
	t_wspos	wspos;

	wspos.col_pos = -1;
	wspos.row_pos = 0;
	while (++wspos.col_pos * wscfg->row_nbr + wspos.row_pos < ar->nbr)
	{
		put_color(ar->stats[wspos.col_pos * wscfg->row_nbr + wspos.row_pos]
				, ar->options);
		ft_putstr(ar->names[wspos.col_pos * wscfg->row_nbr + wspos.row_pos]);
		end_color(ar->options);
		if (wspos.row_pos + 1 < wscfg->row_nbr
				&& ((wspos.col_pos * wscfg->row_nbr + wspos.row_pos)
					+ wscfg->row_nbr >= ar->nbr))
		{
			ft_putchar('\n');
			wspos.col_pos = -1;
			wspos.row_pos++;
		}
		else
			print_space(&wspos, ar, wscfg);
	}
}

void		print_row(t_arr_args *ar)
{
	struct winsize	ws;
	int				max_width;
	t_wscfg			ws_cfg;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		exit(1);
	max_width = get_max_width(ar->names, ar->nbr);
	ws_cfg.col_size = max_width % 8 ? (max_width / 8) * 8 + 8 : max_width + 8;
	ws_cfg.col_nbr = (ws.ws_col ? ws.ws_col : 80) / ws_cfg.col_size;
	ws_cfg.row_nbr = ar->nbr % ws_cfg.col_nbr
		? (ar->nbr / ws_cfg.col_nbr) + 1 : ar->nbr / ws_cfg.col_nbr;
	p_row(ar, &ws_cfg);
	if (ar->nbr)
		ft_putchar('\n');
}
