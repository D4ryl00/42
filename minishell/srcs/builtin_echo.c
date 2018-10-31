/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:21:17 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/03 16:21:38 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	builtin_echo(char **cmdline)
{
	int	i;

	i = 0;
	while (cmdline[++i])
	{
		ft_putstr(cmdline[i]);
		if (cmdline[i + 1])
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
