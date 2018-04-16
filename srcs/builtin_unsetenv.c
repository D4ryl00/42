/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:18:12 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/03 16:18:33 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	builtin_unsetenv(char *var, t_list **env)
{
	if (var)
	{
		ft_lstdelif(env, var, select_env_by_key, del_env_entry);
	}
}
