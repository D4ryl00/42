/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:42:39 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/06 08:30:35 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void	lunch(char *path, char **cmdline, char **environ)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		execve(path, cmdline, environ);
	else
		wait(NULL);
	free(environ);
}
