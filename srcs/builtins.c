/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:21:35 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/03 16:27:07 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	builtins(char **cmdline, t_list **env)
{
	if (ft_strequ("exit", cmdline[0]))
		builtin_exit();
	else if (ft_strequ("env", cmdline[0]))
		builtin_env(*env);
	else if (ft_strequ("setenv", cmdline[0]))
		builtin_setenv(cmdline[1], env);
	else if (ft_strequ("unsetenv", cmdline[0]))
		builtin_unsetenv(cmdline[1], env);
	else if (ft_strequ("cd", cmdline[0]))
		builtin_cd(cmdline[1], env);
	else if (ft_strequ("echo", cmdline[0]))
		builtin_echo(cmdline);
	else
		return (0);
	return (1);
}
