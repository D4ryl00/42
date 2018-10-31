/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:07:32 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/06 08:57:51 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	cd_minus(t_list *node, t_list **env)
{
	char	*str;

	if ((node = ft_lstselect(*env, "OLDPWD", select_env_by_key)))
	{
		str = ft_strdup(p_to_equ_char(node->content) + 1);
		builtin_cd(str, env);
		ft_putendl(str);
		free(str);
	}
	else
		ft_dprintf(2, "minishell: cd: OLDPWD not set\n");
}

static void	cd_default(char *pwd, t_list **env)
{
	char	*str;
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	ft_sprintf(&str, "OLDPWD=%s", oldpwd);
	builtin_setenv(str, env);
	free(str);
	ft_sprintf(&str, "PWD=%s", pwd);
	builtin_setenv(str, env);
	chdir(pwd);
	free(str);
	free(oldpwd);
}

void		builtin_cd(char *path, t_list **env)
{
	t_list	*node;
	char	*pwd;

	pwd = path;
	if (!path)
	{
		if ((node = ft_lstselect(*env, "HOME", select_env_by_key)))
			pwd = p_to_equ_char(node->content) + 1;
		else
		{
			ft_dprintf(2, "minishell: cd: HOME not set\n");
			return ;
		}
	}
	if (ft_strequ("-", pwd))
		cd_minus(node, env);
	else if (!access(pwd, X_OK))
		cd_default(pwd, env);
	else
		ft_dprintf(2, "minishell: cd: %s: Permission denied\n", pwd);
}
