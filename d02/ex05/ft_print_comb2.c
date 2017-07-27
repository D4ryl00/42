/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 01:04:41 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/06 20:58:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = -1;
	while (++a < 99)
	{
		b = a;
		while (++b < 100)
		{
			if (a != b)
			{
				ft_putchar((a / 10) % 10 + '0');
				ft_putchar(a % 10 + '0');
				ft_putchar(' ');
				ft_putchar((b / 10) % 10 + '0');
				ft_putchar(b % 10 + '0');
				if (a != 98 || b != 99)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
