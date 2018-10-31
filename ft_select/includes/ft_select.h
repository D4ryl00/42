/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 21:03:55 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:04:05 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"
# include <termios.h>
# include <sys/ioctl.h>

# define HEADER_HEIGHT 10
# define HEADER_WIDTH 27

typedef struct	s_properties
{
	int				fd;
	unsigned char	activated;
	char			*cursor_move;
	struct winsize	ws;
	char			*enable_full_screen;
	char			*disable_full_screen;
	char			*clear_screen;
	char			*reverse_video;
	char			*normal_video;
	char			*underlining;
	char			*normal_text;
	char			*invisible_cursor;
	char			*visible_cursor;
}				t_properties;

typedef struct	s_item
{
	char			*name;
	unsigned char	selected;
	unsigned char	focus;
}				t_item;

typedef struct	s_term
{
	struct termios	save;
	struct termios	current;
	t_properties	properties;
}				t_term;

typedef struct	s_args
{
	int		line_nbr;
	int		col_nbr;
	int		*col_sizes;
	int		max_col_size;
	t_list	*list;
}				t_args;

t_term			g_term;
t_args			g_args;

int				pchar(int c);
void			set_signals();
void			exit_properly(int sig);
void			free_properties(void);
void			set_term_conf();
void			restore_term();
int				get_max_each_col(int *arr, int nbr);
int				get_max_col_size(void);
int				get_col_nbr(t_list *args);
int				*get_col_sizes(t_list *args, int nbr);
void			get_winsize(int sig);
t_list			*export_args(char **av, int ac);
void			focus_left(t_list *list);
void			focus_right(t_list *list);
void			print();
void			print_header(void);
void			print_commands(void);
void			print_args(void);
int				is_esc_pressed(char *buf, int size);
t_list			*get_focused(t_list *list);
void			delete_item(void *content, size_t size);
int				is_focused(t_list *node, void *data);
void			remove_focused(void);
void			print_selected(void);

#endif
