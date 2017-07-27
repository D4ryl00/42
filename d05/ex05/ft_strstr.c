/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:08:20 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/17 18:46:21 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr;

	if (!*to_find)
		return (str);
	ptr = to_find;
	while (*str && *ptr)
	{
		if (*str != *ptr && ptr == to_find)
			str++;
		else if (*str != *ptr)
		{
			str = str - (ptr - to_find - 1);
			ptr = to_find;
		}
		else
		{
			str++;
			ptr++;
		}
	}
	return (*ptr ? 0 : str - (ptr - to_find));
}
