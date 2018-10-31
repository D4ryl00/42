/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 22:09:25 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/06 09:08:56 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

char	*g_errors[] =
{
	"Not enough space/cannot allocate memory",
	"command not found",
	"No such file or directory",
	"Permission denied"
};

void	exit_perror(enum e_errno num, char *str)
{
	if (str)
		ft_dprintf(2, "minishell: %s: %s\n", str, g_errors[num]);
	else
		ft_dprintf(2, "minishell: %s\n", g_errors[num]);
	exit(1);
}

void	ft_perror(enum e_errno num, char *str)
{
	if (str)
		ft_dprintf(2, "minishell: %s: %s\n", str, g_errors[num]);
	else
		ft_dprintf(2, "minishell: %s\n", g_errors[num]);
}
