/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 23:33:58 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/13 01:02:30 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (*src)
	{
		if (count + 1 < size)
			*dest++ = *src;
		src++;
		count++;
	}
	if (size > 0)
		*dest = '\0';
	return (count);
}
