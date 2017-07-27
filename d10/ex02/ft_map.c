/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:47:09 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/20 13:58:22 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*save;
	int	i;

	save = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		save[i] = f(tab[i]);
		i++;
	}
	return (save);
}
