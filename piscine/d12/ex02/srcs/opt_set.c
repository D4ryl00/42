/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 00:55:13 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:39:09 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"
#include "../includes/line_args.h"
#include "../includes/errors.h"

int		opt_l_set_value(t_line_args *line_args, int index, int *i
			, int ac, char **av)
{
	if (line_args->opt_values[index].type == flag)
	{
		if (!(line_args->opt_values[index].value = ft_strdup("1")))
			return (1);
		(*i)++;
		return (0);
	}
	if (*i + 1 < ac && av[*i + 1][0] != '-')
	{
		if (!(line_args->opt_values[index].value = ft_strdup(av[*i + 1])))
			return (1);
		*i += 2;
		return (0);
	}
	print_err("Error in opt_l_name_value: option value expected");
	return (1);
}

int		opt_s_set_value(t_line_args *line_args, int index, int *i
			, int ac, char **av)
{
	char	*p;

	if (line_args->opt_values[index].type == flag)
	{
		p = "1";
		(*i)++;
	}
	else if (av[*i][2])
		p = &av[(*i)++][2];
	else if (*i + 1 < ac && av[*i + 1][0] != '-')
	{
		p = av[*i + 1];
		*i += 2;
	}
	else
	{
		print_err("Error in opt_s_name_value: option value expected");
		return (1);
	}
	if (!(line_args->opt_values[index].value = ft_strdup(p)))
		return (1);
	return (0);
}
