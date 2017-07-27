/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:59:29 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/18 22:05:10 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	int		length;
	int		i;
	int		j;
	char	*str;

	length = 0;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			length++;
	}
	str = malloc(sizeof(char) * (length + argc - 1));
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			*str++ = argv[i][j];
		if (i < argc - 1)
			*str++ = '\n';
	}
	*str = '\0';
	return (str - length - argc + 2);
}
