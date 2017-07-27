/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:22:01 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/22 13:28:25 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_opp.h"
#include "../includes/eval_expr.h"
#include "../includes/ft_tools_print.h"

/*int	ft_get_operator(int (**f)(int, int), char *str)
{
	int i;

	i = 0;
	while (g_opptab[i].opp[0])
	{
		if (!ft_strcmp(g_opptab[i].opp, str))
		{
			*f = g_opptab[i].f;
			return (1);
		}
		i++;
	}
	*f = g_opptab[i].f;
	return (0);
}*/

int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
