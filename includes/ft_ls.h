/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:56:39 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/04 13:37:37 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_options
{
	unsigned char	l;
	unsigned char	g;
	unsigned char	d;
	unsigned char	big_r;
	unsigned char	a;
	unsigned char	r;
	unsigned char	t;
	unsigned char	u;
	unsigned char	f;
	unsigned char	one;
	unsigned char	big_g;
	unsigned char	big_h;
}				t_options;

typedef struct	s_file
{
	char		*name;
	char		*path;
	struct stat	*stats;
}				t_file;

typedef struct	s_args
{
	t_options	options;
	t_list		*files;
	t_list		*dirs;
	int			(*cmp)(t_list *, t_list*);
	signed char	print_path;
	signed char	print_blocks;
}				t_args;

typedef struct	s_arr_args
{
	char		**names;
	t_options	*options;
	struct stat	**stats;
	int			nbr;
}				t_arr_args;

typedef struct	s_wscfg
{
	int	col_size;
	int	col_nbr;
	int	row_nbr;
}				t_wscfg;

typedef struct	s_wspos
{
	int	col_pos;
	int	row_pos;
}				t_wspos;

void			print_usage(char option);
void			str_perror(char *error);
void			parse_argline(t_args *args, int argc, char **argv);
void			get_options(t_args *args, int argc, char **argv, int *ac);
void			get_options2(t_args *args, char **argv, int *ac, int i);
void			insert_node_to_list(t_list **list, t_list *node, t_args *args);
int				sort_by_modif_time(t_list *l1, t_list *l2);
int				sort_by_access_time(t_list *l1, t_list *l2);
int				sort_by_name(t_list *l1, t_list *l2);
signed char		get_args_stats(struct stat *stats, char *name
		, t_options *options);
signed char		get_stats(struct stat *stats, char *name);
signed char		load_list_of_files(t_args *args);
t_list			*create_child_dir_node(t_list *node);
void			delete_file(void *content, size_t size);
void			delete_dir(void *content, size_t size);
void			print_args(t_args *args);
void			print_row(t_arr_args *args);
char			get_file_type(struct stat *stats);
char			get_file_ur_perm(struct stat *stats);
char			get_file_uw_perm(struct stat *stats);
char			get_file_ux_perm(struct stat *stats);
char			get_file_gr_perm(struct stat *stats);
char			get_file_gw_perm(struct stat *stats);
char			get_file_gx_perm(struct stat *stats);
char			get_file_or_perm(struct stat *stats);
char			get_file_ow_perm(struct stat *stats);
char			get_file_ox_perm(struct stat *stats);
char			get_file_ext_attr(char *path);
void			fill_max_width(int *max_width, t_args *args);
int				get_max_width_hd(t_list *files);
int				get_max_width_uname(t_list *files);
int				get_max_width_gname(t_list *files);
int				get_max_width_major(t_list *files);
int				get_max_width_size(t_list *files);
void			printl_print1(t_file *file, t_args *args, int *max_width);
void			printl_print2(t_file *file, t_args *args);
char			*get_uname(struct stat *stat);
char			*get_gname(struct stat *stat);
char			*get_date(t_args *args);
quad_t			get_total_blocks(t_list *files);
void			put_color(struct stat *stats, t_options *options);
void			end_color(t_options *options);

#endif
