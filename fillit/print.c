/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:38:40 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/24 13:36:01 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

unsigned char	print_usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	return (1);
}

unsigned char	print_error(void)
{
	ft_putendl("error");
	return (1);
}

void			print_result(t_grid *result)
{
	int a;
	int b;

	a = 0;
	while (a < result->size)
	{
		b = -1;
		while (++b < result->size)
			ft_putchar(result->tab[a][b]);
		if (!(a == result->size - 1))
			ft_putchar('\n');
		a++;
	}
}
