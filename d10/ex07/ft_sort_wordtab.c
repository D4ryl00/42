/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 03:05:30 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/19 03:43:29 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_ptrswap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_wordtab_recursive(char **tab, int size)
{
	int i;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ft_ptrswap(&tab[i], &tab[i + 1]);
		}
		i++;
	}
	ft_sort_wordtab_recursive(tab, size - 1);
}

void	ft_sort_wordtab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	ft_sort_wordtab_recursive(tab, i);
}
