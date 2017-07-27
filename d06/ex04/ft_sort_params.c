/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:03:28 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/13 15:30:59 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_integer_table(char **tab, int size)
{
	int i;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
		}
		i++;
	}
	ft_sort_integer_table(tab, size - 1);
}

int		main(int argc, char **argv)
{
	int i;

	ft_sort_integer_table(argv + 1, argc - 1);
	i = 1;
	while (i++ < argc)
	{
		argv++;
		while (**argv)
			ft_putchar(*(*argv)++);
		ft_putchar('\n');
	}
	return (0);
}
