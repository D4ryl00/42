/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:19:00 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/08 11:28:51 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	if (!(arr = (int *)malloc(sizeof(int) * size)))
		return (0);
	i = -1;
	while (++i < size)
		arr[i] = min + i;
	return (arr);
}
