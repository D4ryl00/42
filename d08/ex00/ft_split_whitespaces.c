/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 00:15:28 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/17 10:17:19 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_str(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || (*str >= 7 && *str <= 13)))
			str++;
		if (*str && !(*str == ' ' || (*str >= 7 && *str <= 13)))
			count++;
		while (*str && !(*str == ' ' || (*str >= 7 && *str <= 13)))
			str++;
	}
	return (count);
}

void	count_char(char *str, int *count_char)
{
	int i;

	i = 0;
	while (*str)
	{
		count_char[i] = 0;
		while (*str && (*str == ' ' || (*str >= 7 && *str <= 13)))
			str++;
		while (*str && !(*str == ' ' || (*str >= 7 && *str <= 13)))
		{
			count_char[i]++;
			str++;
		}
		i++;
	}
}

void	fill_tab(char *str, char **tab, int nbr_str)
{
	int i;
	int	j;

	i = 0;
	while (*str)
	{
		j = 0;
		while (*str && (*str == ' ' || (*str >= 7 && *str <= 13)))
			str++;
		while (*str && !(*str == ' ' || (*str >= 7 && *str <= 13)))
			tab[i][j++] = *str++;
		if (i < nbr_str)
		{
			tab[i][j] = '\0';
			i++;
		}
	}
	tab[i] = 0;
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		nbr_str;
	int		*nbr_char;
	int		i;

	nbr_str = count_str(str);
	if ((nbr_char = malloc(sizeof(int) * nbr_str)) == 0)
		return (0);
	count_char(str, nbr_char);
	if ((tab = malloc(sizeof(char*) * (nbr_str + 1))) == 0)
		return (0);
	i = 0;
	while (i < nbr_str)
	{
		if ((tab[i] = malloc(sizeof(char) * (nbr_char[i] + 1))) == 0)
			return (0);
		i++;
	}
	fill_tab(str, tab, nbr_str);
	return (tab);
}
