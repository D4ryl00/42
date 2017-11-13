/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_line_args.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:31:35 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:36:13 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARG_LINE_H
# define T_ARG_LINE_H

#include "t_opt.h"

typedef struct	s_line_args
{
	int			opt_index;
	int			opt_max;
	t_opt		*opt_values;
	char		**arg_values;
}				t_line_args;

#endif
