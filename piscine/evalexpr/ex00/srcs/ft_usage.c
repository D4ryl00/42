/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 03:54:59 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/19 10:00:42 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_usage(int a, int b)
{
	(void)a;
	(void)b;
	ft_putstr("error : only [ + - * / % ] are accepted.\n");
	return (0);
}
