/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_args.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 00:55:46 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:34:50 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_LINE_H
# define ARG_LINE_H

#include "t_line_args.h"

t_line_args		*line_args_init(int opt_max, int ac);
void			line_args_free(t_line_args *line_args);
int				line_args_parsing(t_line_args *line_args, int ac, char **av);

#endif
