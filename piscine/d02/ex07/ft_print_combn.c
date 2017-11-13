/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:09:08 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/07 12:21:48 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_separator(int n, char digits[n])
{
	if (digits[0] != (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combnr(int n, char digits[n], int level)
{
	int i;

	while (1)
	{
		if (digits[level] > 9)
		{
			digits[n - 1] = 0;
			return ;
		}
		i = 0;
		if (level + 1 == n)
		{
			while (i < n)
				ft_putchar(digits[i++] + '0');
			ft_print_separator(n, digits);
		}
		else
		{
			digits[level + 1] = digits[level] + 1;
			ft_print_combnr(n, digits, level + 1);
		}
		digits[level]++;
	}
}

void	ft_print_combn(int n)
{
	char digits[n];

	digits[0] = 0;
	ft_print_combnr(n, digits, 0);
}
