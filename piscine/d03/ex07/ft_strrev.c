/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:06:58 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/07 06:26:32 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char c;
	char *p1;
	char *p2;

	p1 = str;
	p2 = str;
	while (*p2++)
		;
	p2 -= 2;
	while (p1 <= p2)
	{
		c = *p2;
		*p2 = *p1;
		*p1 = c;
		p1++;
		p2--;
	}
	return (str);
}
