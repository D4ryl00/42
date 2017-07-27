/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 01:10:33 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/18 21:34:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		count;
	char	*ptr;
	char	*tmp;

	if (src == 0)
		return (0);
	count = 0;
	ptr = src;
	while (*ptr++)
		count++;
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (0);
	tmp = ptr;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (ptr);
}
