/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:15:37 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/13 13:23:13 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	char	*ptr;
	int		i;

	i = 1;
	while (argc-- - 1)
	{
		ptr = argv[i++];
		while (*ptr)
			ft_putchar(*ptr++);
		ft_putchar('\n');
	}
	return (0);
}
