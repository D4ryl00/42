/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 23:07:36 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 14:21:43 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <xlocale.h>
#include <string.h>

#include "ex05/ft_strstr.c"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	printf("%s\n", ft_strstr(argv[1], argv[2]));
	printf("%s\n", strstr(argv[1], argv[2]));
	return (0);
}
