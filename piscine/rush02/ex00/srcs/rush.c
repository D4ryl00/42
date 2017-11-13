/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:47:14 by jroussel          #+#    #+#             */
/*   Updated: 2017/07/22 20:42:16 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ext_is_valid(char *str, int x, int line, char *patern)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	if (str[line + i++] == patern[line > 0 ? 4 : 0])
		len++;
	else
		return (0);
	while (str[line + i++] == patern[line > 0 ? 5 : 1])
		len++;
	if (x > 1)
	{
		if (str[line + i - 1] == patern[line > 0 ? 6 : 2]
				&& str[line + i] == '\n')
			len++;
		else
			return (0);
	}
	return (x == len);
}

int		mid_is_valid(char *str, int x, int y, char c)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while (str[x + 1 + i] == c || str[x + 1 + i] == ' '
				|| str[x + 1 + i] == '\n')
	{
		if (str[x + 1 + i] == '\n')
		{
			if ((i - result) % x != 0)
				return (0);
			result++;
		}
		i++;
	}
	return (result == (y - (y > 1 ? 2 : 1)));
}

int		rush_is_valid(char *str, int x, int y, char *patern)
{
	if (x < 1 || y < 1)
		return (0);
	if (y == 1)
		return (ext_is_valid(str, x, 0, patern));
	return (ext_is_valid(str, x, 0, patern)
		&& mid_is_valid(str, x, y, patern[3])
		&& ext_is_valid(str, x, (x + 1) * (y - 1), patern));
}
