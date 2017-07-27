/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:52:11 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/11 09:13:22 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	res;
	int	coef;

	res = 0;
	coef = 1;
	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		coef = *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0') * coef;
	return (res);
}
