/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:17:00 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/03 16:33:46 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

void	builtin_setenv(char *var, t_list **env)
{
	char	*p1;
	int		lname;
	t_list	*penv;

	if (var && (p1 = p_to_equ_char(var)) && p1 != var)
	{
		penv = *env;
		lname = p1 - var + 1;
		while (penv)
		{
			if (ft_strnequ(var, penv->content, lname))
			{
				free(penv->content);
				if (!(penv->content = ft_strdup(var)))
					exit_perror(ENOMEM, NULL);
				return ;
			}
			penv = penv->next;
		}
		if (!(ft_lstpushback(env, var, ft_strlen(var) + 1)))
			exit_perror(ENOMEM, NULL);
	}
}
