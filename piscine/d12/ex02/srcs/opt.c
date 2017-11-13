/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:24:19 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:38:11 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/opt.h"
#include "../includes/t_line_args.h"
#include "../includes/t_opt.h"
#include "../includes/opt_get.h"
#include "../includes/errors.h"

int		opt_add(t_line_args *line_args, char s_name, char *l_name
			, enum e_opt_type type)
{
	int i;

	i = line_args->opt_index;
	if (i == line_args->opt_max)
	{
		print_err("Error in options_add: No more space in options array");
		return (1);
	}
	line_args->opt_values[i].s_name = s_name;
	line_args->opt_values[i].l_name = l_name;
	line_args->opt_index += 1;
	line_args->opt_values[i].type = type;
	return (0);
}

char	*opt_get_value(t_line_args *line_args, char *str)
{
	if (str[1])
		return (opt_l_get_value(line_args, str));
	return (opt_s_get_value(line_args, str));
}
