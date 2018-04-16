/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:14:31 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/01 22:04:33 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "stdlib.h"

void	free_strarr(char ***cmdline)
{
	char	**save;

	save = *cmdline;
	while (**cmdline)
	{
		free(**cmdline);
		(*cmdline)++;
	}
	free(save);
	*cmdline = NULL;
}
