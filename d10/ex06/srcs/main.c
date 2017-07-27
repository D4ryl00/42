/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:22:01 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/19 10:13:28 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_opp.h"
#include "../includes/ft.h"

int	ft_get_operator(int (**f)(int, int), char *str)
{
	int i;

	i = 0;
	while (g_opptab[i][0])
	{
		if (!ft_strcmp(g_opptab[i], str))
		{
			*f = g_functab[i];
			return (1);
		}
		i++;
	}
	*f = g_functab[i];
	return (0);
}

int	main(int argc, char **argv)
{
	int result;
	int	(*f)(int, int);
	int no_error;

	no_error = 0;
	if (argc != 4)
		return (1);
	if (!ft_strcmp(argv[2], "/") && !ft_strcmp(argv[3], "0"))
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	if (!ft_strcmp(argv[2], "%") && !ft_strcmp(argv[3], "0"))
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	no_error = ft_get_operator(&f, argv[2]);
	result = f(ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putnbr(result);
	ft_putchar('\n');
	return (0);
}
