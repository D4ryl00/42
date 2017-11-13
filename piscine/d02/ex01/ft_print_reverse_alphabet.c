/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:33:29 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/06 22:28:29 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	c;

	i = 0;
	c = 'z';
	while (i < 26)
	{
		ft_putchar(c);
		c = c - 1;
		i = i + 1;
	}
}
