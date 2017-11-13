/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:47:03 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 00:51:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count_dest;
	unsigned int	count_src;
	unsigned int	rst;
	unsigned int	tmp;

	tmp = size;
	count_dest = 0;
	count_src = 0;
	while (tmp-- && *dest++)
		count_dest++;
	while (*src++)
		count_src++;
	dest--;
	src -= count_src + 1;
	rst = size - count_dest;
	if (rst == 0)
		return (count_dest + count_src);
	while (*src && rst != 1)
	{
		*dest++ = *src++;
		rst--;
	}
	*dest = '\0';
	return (count_dest + count_src);
}
