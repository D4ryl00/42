/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:25:15 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/13 09:56:17 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	float				approx;
	unsigned int		sqrt;
	unsigned int		tmp;

	if (nb < 0 || nb > 2147483647)
		return (0);
	approx = 1.;
	sqrt = 1;
	tmp = 0;
	while (tmp != sqrt)
	{
		approx = 0.5 * ((float)approx + nb / (float)approx);
		tmp = sqrt;
		sqrt = (unsigned int)approx;
	}
	if ((int)(sqrt * sqrt) == nb)
		return ((int)sqrt);
	return (0);
}
