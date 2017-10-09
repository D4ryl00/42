/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:07:34 by rbarbero          #+#    #+#             */
/*   Updated: 2017/09/21 10:31:34 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strdup(char *src)
{
	int		count;
	char	*ptr;
	char	*tmp;

	if (!src)
		return (0);
	count = 0;
	ptr = src;
	while (*ptr++)
		count++;
	if (!(ptr = malloc(sizeof(char) * (count + 1))))
		return (0);
	tmp = ptr;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (ptr);
}
