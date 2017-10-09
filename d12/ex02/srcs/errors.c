/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:08:33 by rbarbero          #+#    #+#             */
/*   Updated: 2017/09/20 11:18:04 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_errno(char *msg, int err)
{
	int	power;
	int	tmp;
	int	digit;

	tmp = err;
	power = 1;

	while (tmp /= 10)
		power *= 10;
	while (*msg)
		write(2, msg++, 1);
	write(2, " code ", 1);
	while (power)
	{
		digit = err / power + '0';
		write(2, &digit, 1);
		power /= 10;
	}
	write(2, "\n", 1);
}

void	print_err(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
}
