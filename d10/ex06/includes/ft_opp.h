/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:08:38 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/19 03:47:24 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPP_H
# define FT_OPP_H

# include "t_opp.h"
# include "f_opp.h"

int		(*g_functab[])(int, int) =
{
	&ft_add,
	&ft_sub,
	&ft_mul,
	&ft_div,
	&ft_mod,
	&ft_usage
};

char	*g_opptab[] =
{
	"+",
	"-",
	"*",
	"/",
	"%",
	""
};

#endif
