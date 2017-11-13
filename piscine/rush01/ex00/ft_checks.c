/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:55:30 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 22:05:04 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checks.h"

int	check_double_number(char *str, int size)
{
	int i;

	i = 0;
	if (size < 2)
		return (1);
	while (i < size - 1)
	{
		if (str[0] != '.' && str[i] >= '0' && str[i] <= '9')
		{
			if (str[0] == str[i + 1])
				return (1);
			i++;
		}
		else
			i++;
	}
	check_double_number(++str, size - 1);
	return (0);
}

int	check_line(char *str)
{
	int		i;
	int		count;
	char	*ptr;

	i = 0;
	count = 0;
	ptr = str;
	while (*str == '.' || (*str >= '1' && *str <= '9'))
	{
		str++;
		count++;
	}
	if (count != 9)
		return (0);
	if (check_double_number(ptr, count))
		return (0);
	return (1);
}

int	is_ok_block(char **tab, int row, int line, char nbr)
{
	int start_line;
	int start_row;
	int i;
	int j;

	start_line = (line / 3) * 3;
	start_row = (row / 3) * 3;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (tab[start_row + i][start_line + j++] == nbr)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_ok_row(char **tab, int row, char nbr)
{
	int	i;

	i = 0;
	while (i < 9)
		if (tab[row][i++] == nbr)
			return (0);
	return (1);
}

int	is_ok_line(char **tab, int line, char nbr)
{
	int	i;

	i = 0;
	while (i < 9)
		if (tab[i++][line] == nbr)
			return (0);
	return (1);
}
