/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 06:43:39 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 06:28:00 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void	option_l(t_args *args)
{
	args->options.l = 1;
	args->options.one = 0;
	args->options.big_h = 0;
}

static void	option_d(t_args *args)
{
	args->options.d = 1;
	args->options.big_h = 0;
}

void		get_options(t_args *args, int argc, char **argv, int *ac)
{
	int	i;

	while (++(*ac) < argc && argv[*ac][0] == '-' && argv[*ac][1])
	{
		i = 0;
		while (argv[*ac][++i])
		{
			if (argv[*ac][i] == 'l')
				option_l(args);
			else if (argv[*ac][i] == 'g')
				args->options.g = 1;
			else if (argv[*ac][i] == 'd')
				option_d(args);
			else if (argv[*ac][i] == 'R')
				args->options.big_r = 1;
			else if (argv[*ac][i] == 'a')
				args->options.a = 1;
			else if (argv[*ac][i] == 'r')
				args->options.r = 1;
			else
				get_options2(args, argv, ac, i);
		}
	}
}
