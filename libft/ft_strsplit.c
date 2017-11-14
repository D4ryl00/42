/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:56:55 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/14 16:07:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			len++;
		while (*s && *s != c)
			s++;
	}
	return (len);
}

static char	**add_words(char **ar, const char *s, char c)
{
	int			i;
	const char	*start;
	const char	*end;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		end = s;
		if (end - start > 0)
		{
			if (!(ar[i] = (char *)malloc(end - start + 1)))
				return (NULL);
			ft_strncpy(ar[i], start, end - start);
			ar[i++][end - start] = '\0';
		}
	}
	return (ar);
}

char		**ft_strsplit(char const *s, char c)
{
	int			size;
	char		**ar;

	size = count_words(s, c);
	if (!(ar = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	ar[size] = 0;
	if (!add_words(ar, s, c))
		return (NULL);
	return (ar);
}