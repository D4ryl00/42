/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:40:33 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 16:50:06 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int	*ptr;
	int count;
	int to_find;

	while (*tab)
	{
		count = 0;
		to_find = *tab;
		ptr = tab;
		while (*(++ptr))
		{
			if (*ptr == to_find)
				count++;
		}
		if (count % 2)
			return (to_find);
		tab++;
	}
	return (0);
}
