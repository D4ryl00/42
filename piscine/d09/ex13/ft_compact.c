/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 12:36:00 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 14:08:25 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compact(char **tab, int lenght)
{
	int		i;
	int		j;
	int		res;
	char	**ptr;

	i = -1;
	res = 0;
	ptr = tab;
	while (++i < lenght)
	{
		j = 0;
		if (tab[i] == 0)
		{
			while ((i + j) < lenght && tab[i + j] == 0)
				j++;
			if (tab[i + j] && (i + j) < lenght)
			{
				tab[i] = tab[i + j];
				tab[i + j] = 0;
			}
		}
	}
	while (*ptr++)
		res++;
	return (res);
}
