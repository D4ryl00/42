/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:49:29 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/13 14:58:00 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	int		coef;

	nbr = 0;
	coef = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		coef = *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str++ - '0') * coef;
		if (nbr > 2147483647)
			return (-1);
		if (nbr < (-2147483647 - 1))
			return (0);
	}
	return ((int)nbr);
}
