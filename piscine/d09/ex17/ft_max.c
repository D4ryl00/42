/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:04:34 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 16:11:19 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int i;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
		}
		i++;
	}
	ft_sort_integer_table(tab, size - 1);
}

int		ft_max(int *tab, int length)
{
	ft_sort_integer_table(tab, length);
	return (tab[length - 1]);
}
