/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:46:30 by rbarbero          #+#    #+#             */
/*   Updated: 2018/01/15 18:20:38 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtoupper(char *s)
{
	int	i;

	i = -1;
	if (s)
		while (s[++i])
			s[i] = ft_toupper(s[i]);
}
