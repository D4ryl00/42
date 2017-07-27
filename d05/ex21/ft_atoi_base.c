/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:32:02 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/27 20:54:23 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		value_base(char *base)
{
	int	res;

	res = 0;
	while (*base++)
		res++;
	return (res);
}

int		value_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int		is_in_base(char c, char *base)
{
	while (*base)
		if (c == *base++)
			return (1);
	return (0);
}

int		check_double(char *base)
{
	char	*ptr;

	if (!*(base + 1))
		return (1);
	ptr = base + 1;
	while (*ptr)
		if (*ptr++ == *base)
			return (0);
	return (check_double(base + 1));
}

int check_base(char *base)
{
	char *ptr;

	ptr = base;
	if (!base || !*base || !(base + 1))
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	base = ptr;
	if (!check_double(base))
		return (0);
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int	coef;
	int	res;
	int	v_base;

	if (!check_base(base))
		return (0);
	v_base = 0;
	while (base[v_base])
		v_base++;
	res = 0;
	coef = 1;
	while ((*str >= 7 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		coef = *str++ == '-' ? -1 : 1;
	while (is_in_base(*str, base))
		res = res * v_base + value_digit(*str++, base) * coef;
	return (res);
}
