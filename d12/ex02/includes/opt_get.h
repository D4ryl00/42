/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_get.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:21:21 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:35:22 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_GET_H
# define OPT_GET_H

#include "t_line_args.h"

int		opt_s_get_index(t_line_args *line_args, char *str);
int		opt_l_get_index(t_line_args *line_args, char *str);
char	*opt_l_get_value(t_line_args *line_args, char *str);
char	*opt_s_get_value(t_line_args *line_args, char *str);

#endif
