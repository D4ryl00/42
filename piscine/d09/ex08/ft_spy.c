/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 02:40:52 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 04:04:04 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_search(char *dest, char *to_find)
{
	while (*dest && *to_find
			&& (*dest == *to_find || (*dest | 0x20) == *to_find))
	{
		dest++;
		to_find++;
	}
	if (!*to_find && (!*dest || *dest == ' ' || (*dest >= 7 && *dest <= 13)))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*ptr;

	i = 1;
	while (i < argc)
	{
		ptr = argv[i++];
		while ((*ptr >= 7 && *ptr <= 13) || *ptr == ' ')
			ptr++;
		if (ft_search(ptr, "president") || ft_search(ptr, "attack")
				|| ft_search(ptr, "powers"))
			write(1, "Alert!!!", 8);
	}
}
