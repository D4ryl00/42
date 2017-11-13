/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:29:56 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:35:47 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT__H

#include "t_line_args.h"

int				opt_add(t_line_args *line_args, char s_name, char *l_name
					, enum e_opt_type type);
char			*opt_get_value(t_line_args *line_args, char *str);

#endif
