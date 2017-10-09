/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:34:04 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 17:34:48 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OPT_H
# define T_OPT_H

enum	e_opt_type
{
	flag,
	optional,
	mandatory
};

typedef struct	s_opt
{
	char			s_name;
	char			*l_name;
	char			*value;
	enum e_opt_type type;
}				t_opt;

#endif
