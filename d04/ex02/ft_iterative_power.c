/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:21:41 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/10 23:55:33 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int res;

	if (power < 0 || nb < -2147483648 || nb > 2147483647)
		return (0);
	if (power == 0)
		return (1);
	res = nb;
	while (power-- > 1)
		res *= nb;
	return (res);
}
