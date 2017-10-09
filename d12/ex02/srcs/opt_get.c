/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:06:58 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:38:45 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/t_line_args.h"
#include "../includes/opt_get.h"
#include "../includes/errors.h"
#include "../includes/ft_string.h"

int		opt_s_get_index(t_line_args *line_args, char *str)
{
	int		i;
	
	i = -1;
	while (++i < line_args->opt_max)
		if (line_args->opt_values[i].s_name == str[1])
			return (i);
	print_err("Error in opt_s_name_index: unknown option");
	return (-1);
}

int		opt_l_get_index(t_line_args *line_args, char *str)
{
	int		i;
	
	i = -1;
	while (++i < line_args->opt_max)
		if (!ft_strcmp(line_args->opt_values[i].l_name, &str[2]))
			return (i);
	print_err("Error in opt_l_name_index: unknown option");
	return (-1);
}

char	*opt_l_get_value(t_line_args *line_args, char *str)
{
	int	index;

	index = opt_l_get_index(line_args, str);
	return (line_args->opt_values[index].value);
}

char	*opt_s_get_value(t_line_args *line_args, char *str)
{
	int	index;

	index = opt_s_get_index(line_args, str);
	return (line_args->opt_values[index].value);
}
