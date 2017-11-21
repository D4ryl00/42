/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:35:18 by sderet            #+#    #+#             */
/*   Updated: 2017/11/20 19:45:15 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	err_argnbr(void)
{
	ft_putendl("usage: ./fillit source_file");
}

char	err_std(void)
{
	ft_putendl("error");
	return (1);
}
