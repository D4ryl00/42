/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:28:27 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/06 00:53:39 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	char digits[3];

	digits[0] = '0';
	while (digits[0] < '8')
	{
		digits[1] = digits[0] + 1;
		while (digits[1] < '9')
		{
			digits[2] = digits[1] + 1;
			while (digits[2] <= '9')
			{
				ft_putchar(digits[0]);
				ft_putchar(digits[1]);
				ft_putchar(digits[2]);
				if (digits[0] != '7' || digits[1] != '8' || digits[2] != '9')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				digits[2] = digits[2] + 1;
			}
			digits[1] = digits[1] + 1;
		}
		digits[0] = digits[0] + 1;
	}
}
