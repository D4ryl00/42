/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:29:28 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/07 14:18:32 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		direct_access(char **cmdline, t_list *env)
{
	char	*path;

	if (!access(cmdline[0], F_OK))
	{
		if (!access(cmdline[0], X_OK))
		{
			path = cmdline[0];
			cmdline[0] = ft_getfilename(cmdline[0]);
			lunch(path, cmdline, export_env(env));
			free(path);
		}
		else
			ft_perror(EACCES, cmdline[0]);
	}
	else
		ft_perror(ENOCMD, cmdline[0]);
}

static char	*is_in_path(char *filename, char **dirs)
{
	char	*path;
	int		i;

	i = -1;
	while (dirs[++i])
	{
		if (ft_sprintf(&path, "%s/%s", dirs[i], filename) < 0)
			exit_perror(ENOMEM, NULL);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	return (NULL);
}

void		env_path_access(char **cmdline, t_list *env)
{
	char	**dirs;
	char	*path;
	t_list	*node;

	path = NULL;
	if ((node = ft_lstselect(env, "PATH", select_env_by_key)))
	{
		dirs = ft_strsplit(p_to_equ_char(node->content) + 1, ':');
		if ((path = is_in_path(cmdline[0], dirs)))
		{
			if (!access(path, X_OK))
				lunch(path, cmdline, export_env(env));
			else
				ft_perror(EACCES, cmdline[0]);
			free(path);
		}
		else
			ft_perror(ENOCMD, cmdline[0]);
		free_strarr(&dirs);
	}
	else
		direct_access(cmdline, env);
}
