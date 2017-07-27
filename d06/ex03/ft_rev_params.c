/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:29:29 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/13 15:33:57 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	argv += argc - 1;
	while (--argc > 0)
	{
		while (**argv)
			ft_putchar(*(*argv)++);
		ft_putchar('\n');
		argv--;
	}
	return (0);
}
