/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:38:40 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/21 19:23:03 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		print_usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	return (1);
}

int		print_error(void)
{
	ft_putendl("error");
	return (1);
}

void	print_result(char **result)
{
}
