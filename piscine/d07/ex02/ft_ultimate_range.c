/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:24:57 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/18 21:36:31 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!range[0])
	{
		*range = 0;
		return (0);
	}
	i = 0;
	while (i < (max - min))
	{
		range[0][i] = min + i;
		i++;
	}
	return (max - min);
}
