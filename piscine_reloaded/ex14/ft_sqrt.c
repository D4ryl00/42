/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:21:18 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/07 17:19:41 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	float	approx;
	int		tmp;
	int		sqrt;

	if (nb < 1 || nb > 2147483647)
		return (0);
	approx = 1.;
	tmp = 0;
	sqrt = 1;
	while (tmp != sqrt)
	{
		approx = 0.5 * (approx + nb / approx);
		tmp = sqrt;
		sqrt = (int)approx;
	}
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (0);
}
