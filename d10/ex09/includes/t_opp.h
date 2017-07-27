/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:28:11 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/19 10:29:24 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OPP_H
# define T_OPP_H

typedef struct	s_opp
{
	char	*opp;
	int		(*f)(int, int);
}				t_opp;

#endif
