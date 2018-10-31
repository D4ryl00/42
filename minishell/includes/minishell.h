/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:22:55 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/07 14:16:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"

enum	e_errno
{
	ENOMEM,
	ENOCMD,
	ENOENT,
	EACCES
};

extern char	*g_errors[];

void		exit_perror(enum e_errno num, char *str);
void		ft_perror(enum e_errno num, char *str);
void		env_path_access(char **cmdline, t_list *env);
void		direct_access(char **cmdline, t_list *env);
void		lunch(char *path, char **cmdline, char **environ);
char		**export_env(t_list *env);
void		free_strarr(char ***cmdline);
void		env_dup(t_list **env, char **environ);
char		*p_to_equ_char(char *str);
int			select_env_by_key(t_list *node, void *data);
void		del_env_entry(void *content, size_t size);
int			builtins(char **cmdline, t_list **env);
void		builtin_env(t_list *env);
void		builtin_setenv(char *var, t_list **env);
void		builtin_unsetenv(char *var, t_list **env);
void		builtin_cd(char *path, t_list **env);
void		builtin_echo(char **cmdline);
void		builtin_exit(void);
void		sig_ctrl_c(int sig);

#endif
