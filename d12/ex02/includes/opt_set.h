/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_set.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:23:27 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:35:32 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_SET_H
# define OPT_SET_H

#include "t_line_args.h"

int				opt_l_set_value(t_line_args *line_args, int index, int *i
					, int ac, char **av);
int				opt_s_set_value(t_line_args *line_args, int index, int *i
					, int ac, char **av);

#endif
