/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:01:49 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/10 19:12:40 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int coef;
	int res;

	res = 0;
	coef = 1;
	while ((*str >= 7 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		coef = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0') * coef;
	return (res);
}
