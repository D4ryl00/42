/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:43:15 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/18 18:48:31 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		value_inbase(char digit, char *base)
{
	int	count;

	count = 0;
	while (*base)
	{
		if (digit == *base)
			return (count);
		count++;
		base++;
	}
	return (-1);
}

int		ft_convert_to10(char *nbr, char *base, int base_int)
{
	int	res;

	res = 0;
	while (*nbr)
	{
		res = res * base_int + value_inbase(*nbr, base);
		nbr++;
	}
	return (res);
}

char	*ft_strrev(char *str)
{
	char	c;
	char	*p1;
	char	*p2;

	p1 = str;
	p2 = str;
	while (*p2++)
		;
	p2 -= 2;
	while (p1 <= p2)
	{
		c = *p2;
		*p2 = *p1;
		*p1 = c;
		p1++;
		p2--;
	}
	return (str);
}

char	*ft_convert_tobase(int nbr, char *base, int base_int)
{
	char	*res;
	int		count;
	int		tmp;
	int		test;

	count = 0;
	test = 2;
	tmp = nbr;
	while (test--)
	{
		nbr = tmp;
		while (nbr)
		{
			if (!test)
				*res++ = base[nbr % base_int];
			nbr /= base_int;
			count = test ? count + 1 : count + 0;
		}
		if (test)
			res = malloc(sizeof(char) * (count + 1));
	}
	*res = '\0';
	return (res - count);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		count_bf;
	int		count_bt;
	int		nbr_10;
	char	*result;

	count_bf = 0;
	count_bt = 0;
	while (base_from[count_bf++])
		;
	while (base_to[count_bt++])
		;
	nbr_10 = ft_convert_to10(nbr, base_from, --count_bf);
	result = ft_convert_tobase(nbr_10, base_to, --count_bt);
	ft_strrev(result);
	return (result);
}
