/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:05:35 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/13 13:12:16 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	char	*ptr;

	argc = argc - 1;
	ptr = argv[0];
	while (*ptr)
		ft_putchar(*ptr++);
	ft_putchar('\n');
	return (0);
}
