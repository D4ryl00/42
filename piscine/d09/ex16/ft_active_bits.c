/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:32:28 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 16:00:27 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	int mask;
	int count;

	count = 0;
	mask = 1;
	while (value)
	{
		count += (value & mask) ? 1 : 0;
		value = value >> 1;
	}
	return (count);
}
