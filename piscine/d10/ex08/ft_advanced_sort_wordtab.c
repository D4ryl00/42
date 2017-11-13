/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:24:58 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/19 12:12:28 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ptrswap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_ad_sort_wordtab_r(char **tab, int (*cmp)(char *, char *), int size)
{
	int i;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			ft_ptrswap(&tab[i], &tab[i + 1]);
		}
		i++;
	}
	ft_ad_sort_wordtab_r(tab, cmp, size - 1);
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	ft_ad_sort_wordtab_r(tab, cmp, i);
}
