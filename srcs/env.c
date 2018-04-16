/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:26:12 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 08:17:03 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

void	env_dup(t_list **env, char **environ)
{
	while (*environ)
	{
		if (!(ft_lstpushback(env, *environ
						, sizeof(char) * (ft_strlen(*environ) + 1))))
			exit_perror(ENOMEM, NULL);
		environ++;
	}
}

char	*p_to_equ_char(char *str)
{
	while (*str)
	{
		if (*str == '=')
			return (str);
		str++;
	}
	return (NULL);
}

int		select_env_by_key(t_list *node, void *data)
{
	size_t	len;

	len = p_to_equ_char(node->content) - (char *)node->content;
	return (ft_strnequ(node->content, data, len));
}

void	del_env_entry(void *content, size_t size)
{
	(void)size;
	free(content);
}

char	**export_env(t_list *env)
{
	char	**dest;
	int		i;

	if (!(dest = (char **)malloc(sizeof(char *) * ft_lstsize(env) + 1)))
		exit(1);
	i = 0;
	while (env)
	{
		dest[i++] = env->content;
		env = env->next;
	}
	dest[i] = NULL;
	return (dest);
}
