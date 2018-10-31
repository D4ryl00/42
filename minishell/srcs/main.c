/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:24:42 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/07 14:17:14 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>
#include <signal.h>

static int	prompt(char **input)
{
	ft_putstr("$> ");
	return (get_next_line(0, input));
}

static char	*get_cmd(char **input)
{
	char	*cmd;
	char	*save;
	char	*separator;

	if ((separator = ft_strchr(*input, ';')))
	{
		save = *input;
		if (!(cmd = ft_strsub(*input, 0, separator - *input)))
			exit_perror(ENOMEM, NULL);
		if (!(*input = ft_strsub(*input, separator - *input + 1
						, ft_strlen(separator + 1))))
			exit_perror(ENOMEM, NULL);
		free(save);
	}
	else
	{
		cmd = *input;
		*input = NULL;
	}
	return (cmd);
}

static void	process_input(char **input, t_list **env)
{
	char	*cmd;
	char	**cmdsplit;

	while (*input && (cmd = get_cmd(input)))
	{
		if (!(cmdsplit = ft_strsplit(cmd, ' ')))
			exit_perror(ENOMEM, NULL);
		if (*cmdsplit && builtins(cmdsplit, env))
			;
		else if (*cmdsplit && ft_strchr(cmdsplit[0], '/'))
			direct_access(cmdsplit, *env);
		else if (*cmdsplit)
			env_path_access(cmdsplit, *env);
		free_strarr(&cmdsplit);
		free(cmd);
	}
}

int			main(int argc, char **argv, char **environ)
{
	char	*input;
	t_list	*env;

	(void)argc;
	(void)argv;
	signal(SIGINT, sig_ctrl_c);
	input = NULL;
	env = NULL;
	env_dup(&env, environ);
	while (prompt(&input) > 0)
		process_input(&input, &env);
	return (0);
}
