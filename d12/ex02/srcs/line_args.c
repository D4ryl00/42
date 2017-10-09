/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 00:55:13 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:37:33 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "../includes/line_args.h"
#include "../includes/errors.h"
#include "../includes/opt_get.h"
#include "../includes/opt_set.h"
#include "../includes/opt_check.h"

t_line_args	*line_args_init(int opt_max, int ac)
{
	t_line_args	*line_args;

	if (!(line_args = malloc(sizeof(t_line_args))))
	{
		print_errno("Error in line_args_init:", errno);
		return (0);
	}
	line_args->opt_index = 0;
	line_args->opt_max = opt_max;
	if (!(line_args->opt_values = malloc(sizeof(t_opt) * opt_max)))
	{
		print_errno("Error in line_args_init:", errno);
		return (0);
	}
	if (!(line_args->arg_values = malloc(sizeof(char *) * (ac - 1))))
	{
		print_errno("Error in line_args_init:", errno);
		return (0);
	}
	return (line_args);
}

void	line_args_free(t_line_args *line_args)
{
	int	i;

	i = -1;
	while (++i < line_args->opt_index)
		free(line_args->opt_values[i].value);
	free(line_args->opt_values);
	free(line_args->arg_values);
	free(line_args);
}

int		line_args_parsing(t_line_args *line_args, int ac, char **av)
{
	int	i;
	int	opt_index;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == '-')
			{
				if ((opt_index = opt_l_get_index(line_args, av[i])) < 0
						|| opt_l_set_value(line_args, opt_index, &i, ac, av))
					return (1);
			}
			else if ((opt_index = opt_s_get_index(line_args, av[i])) < 0
					|| opt_s_set_value(line_args, opt_index, &i, ac, av))
				return (1);
		}
		else
			line_args->arg_values[j++] = av[i++];
	}
	line_args->arg_values[j] = 0;
	return (opt_check_mandatories(line_args));
}
