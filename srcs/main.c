/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:39:38 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/04 06:37:33 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void	args_init(t_args *args)
{
	args->cmp = NULL;
	args->files = NULL;
	args->print_path = 0;
	args->print_blocks = 0;
	args->options.l = 0;
	args->options.g = 0;
	args->options.d = 0;
	args->options.big_r = 0;
	args->options.a = 0;
	args->options.r = 0;
	args->options.t = 0;
	args->options.u = 0;
	args->options.f = 0;
	args->options.one = 0;
	args->options.big_g = 0;
	args->options.big_h = 1;
}

int			main(int argc, char **argv)
{
	t_args	args;

	args_init(&args);
	parse_argline(&args, argc, argv);
	while (load_list_of_files(&args))
		print_args(&args);
	return (0);
}
