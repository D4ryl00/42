/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:04:02 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 13:13:01 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if ((str == ptr && (*ptr >= 'a' && *ptr <= 'z'))
				|| ((!(*(ptr - 1) >= 'A' && *(ptr - 1) <= 'Z')
					&& !(*(ptr - 1) >= 'a' && *(ptr - 1) <= 'z')
					&& !(*(ptr - 1) >= '0' && *(ptr - 1) <= '9'))
				&& ((*ptr >= 'a' && *ptr <= 'z')
					|| (*ptr >= 'A' && *ptr <= 'Z'))))
			*ptr &= ~0x20;
		else if (*ptr >= 'A' && *ptr <= 'Z')
			*ptr |= 0x20;
		ptr++;
	}
	return (str);
}
