/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:06:08 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/22 13:28:22 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_str_to_rpn.h"

int	eval_expr(char *str)
{
	int result;

	result = ft_rpn_eval(str);
	return (result);
}
