/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 02:55:00 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/20 09:54:13 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_match(char *charset, char c)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

int		count_items(char *str, char *charset)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = str;
	while (*ptr)
	{
		if (((ptr == str || is_match(charset, *(ptr - 1)))
					&& !is_match(charset, *ptr)))
			count++;
		ptr++;
	}
	return (count);
}

int		count_char(char *begin, char *end)
{
	return (end - begin);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*p;

	p = dest;
	while (n--)
		*dest++ = *src ? *src++ : '\0';
	*dest = '\0';
	return (p);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	char	*ptr;
	int		item;
	int		count;

	item = 0;
	count = 0;
	ptr = str;
	tab = malloc(sizeof(char*) * (count_items(str, charset) + 1));
	while (*str)
	{
		while (*str && is_match(charset, *str))
			str++;
		ptr = str;
		while (*str && !is_match(charset, *str))
			str++;
		count = count_char(ptr, str);
		if (count)
		{
			tab[item] = malloc(sizeof(char) * (count + 1));
			ft_strncpy(tab[item++], ptr, count);
		}
	}
	tab[item] = 0;
	return (tab);
}
