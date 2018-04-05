/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:04:55 by rbarbero          #+#    #+#             */
/*   Updated: 2018/03/31 08:56:48 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	print_usage(char option)
{
	ft_printf("ft_ls: illegal option -- %c\n", option);
	ft_putstr("usage: ft_ls [-1GHRadfglrut] [file ...]\n");
	exit(1);
}

void	str_perror(char *arg)
{
	char	*str;

	if (arg)
	{
		if (*arg)
		{
			if ((str = ft_strjoin("ft_ls: ", arg)))
			{
				perror(str);
				free(str);
			}
			else
				perror(NULL);
		}
		else
			perror("ft_ls");
	}
	else
		perror(NULL);
}
