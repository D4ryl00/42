/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:28:41 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:38:24 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"
#include "../includes/t_line_args.h"
#include "../includes/opt_check.h"

int		opt_check_mandatories(t_line_args *line_args)
{
	int	i;

	i = -1;
	while (++i < line_args->opt_index)
	{
		if (line_args->opt_values[i].type == mandatory
				&& !line_args->opt_values[i].value)
		{
			print_err("Error: mandatory options are missing");
			return (1);
		}
	}
	return (0);
}
