/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_options2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 06:53:45 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/05 07:41:04 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void	option_t(t_args *args)
{
	args->options.t = 1;
	args->cmp = sort_by_modif_time;
}

static void	option_u(t_args *args)
{
	args->options.u = 1;
	args->cmp = sort_by_access_time;
}

static void	option_f(t_args *args)
{
	args->options.f = 1;
	args->options.a = 1;
	args->options.big_h = 0;
}

static void	option_one(t_args *args)
{
	args->options.one = 1;
	args->options.l = 0;
}

void		get_options2(t_args *args, char **argv, int *ac, int i)
{
	if (argv[*ac][i] == 't')
		option_t(args);
	else if (argv[*ac][i] == 'u')
		option_u(args);
	else if (argv[*ac][i] == 'f')
		option_f(args);
	else if (argv[*ac][i] == '1')
		option_one(args);
	else if (argv[*ac][i] == 'G')
		args->options.big_g = 1;
	else if (argv[*ac][i] == 'H')
		args->options.big_h = 1;
	else
		print_usage(argv[*ac][i]);
}
