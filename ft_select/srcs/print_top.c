/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 09:10:19 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/16 06:45:50 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	print_header(void)
{
	ft_putstr_fd("+-+-+  +-+-+-+-+-+-+-+-+-+\n\
|4|2|  |f|t|_|s|e|l|e|c|t|\n\
+-+-+  +-+-+-+-+-+-+-+-+-+\n", g_term.properties.fd);
}

void	print_commands(void)
{
	ft_putstr_fd("Left | right\tNavigate\n", g_term.properties.fd);
	ft_putstr_fd("Space\t\tSelect item\n", g_term.properties.fd);
	ft_putstr_fd("Backspace\tRemove item\n", g_term.properties.fd);
	ft_putstr_fd("Return\t\tValidate\n", g_term.properties.fd);
	ft_putstr_fd("Escape\t\tExit\n", g_term.properties.fd);
	ft_putstr_fd("+-+-+-+-+-+-+-+-+-+-+-+-+-\n", g_term.properties.fd);
}
