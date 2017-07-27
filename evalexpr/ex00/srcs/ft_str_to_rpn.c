/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_rpn2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:17:52 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/23 18:34:47 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_stack.h"
#include "../includes/ft_opp.h"

int	ft_strcmp(char *s1, char *s2) {
	while (*s1 == *s2 && *s1 && *s2) {
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_str_is_nbr(char *str)
{
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || *str == '-'))
			return (0);
		str++;
	}
	return (1);
}

int ft_str_is_op(char *str)
{
	int i;

	i = 0;
	while (g_opptab[i].opp[0])
	{
		if (!ft_strcmp(g_opptab[i].opp, str))
			return (1);
		i++;
	}
	return (0);
}

int	ft_char_is_op(char c)
{
	int i;

	i = 0;
	while (g_opptab[i].opp[0])
	{
		if (*(g_opptab[i].opp) == c) {
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int coef;
	int res;

	res = 0;
	coef = 1;
	while ((*str >= 7 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		coef = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0') * coef;
	return (res);
}

char	*ft_strndup(char *src, int n)
{
	int		count;
	char	*ptr;
	char	*tmp;

	if (src == 0)
		return (0);
	count = 0;
	ptr = src;
	if(!(ptr = malloc(sizeof(char) * (n + 1))))
		return (0);
	tmp = ptr;
	while (*src && count < n)
		*tmp++ = *src++;
	*tmp = '\0';
	return (ptr);
}

int		ft_count_tokens(char *input)
{
	int 	count;
	char	*start;

	start = input;
	count = 0;
	while (*input)
	{
		if (input == start || ((*(input - 1) == ' ' || *(input - 1) == '(')
							   && *input != ' '))
			count++;
		else if (*input == '(' || *input == ')')
			count++;
		input++;
	}
	return (count);
}

char 	**ft_str_to_tokens(char *input)
{
	char	*start;
	char	**tab;
	int		size;
	int		count;

	count = 0;
	start = input;
	size = ft_count_tokens(input);
	tab = malloc(sizeof(char*) * (size + 1));
	while (*input)
	{
		if (*input == '(')
			tab[count++] = ft_strndup("(", 2);
		else if (*input == ')')
			tab[count++] = ft_strndup(")", 2);
		else if (input == start || ((*(input - 1) == ' '
					 || *(input - 1) == '(') && *input != ' '))
		{
			start = input;
			while (*input != ' ')
				input++;
			tab[count++] = ft_strndup(start, input - start);
		}
		else if (ft_char_is_op(*input))
			tab[count++] = ft_strndup(input, 2);
		input++;
	}
	return (tab);
}

int		ft_get_op_pres(char *str)
{
	int i;

	i = 0;
	while (g_opptab[i].opp[0])
	{
		if (!ft_strcmp(g_opptab[i].opp, str))
			return (g_opptab[i].pres);
		i++;
	}
	return (0);
}

int		ft_rpn_eval(char *input)
{
	int result;
	t_stack	*stack_op;
	t_stack	*stack_nbr;
	char 	**tokens;

	result = 0;
	if (!(stack_op = ft_stack_create(4096)))
		return (0);
	if (!(stack_nbr = ft_stack_create(4096)))
		return (0);
	tokens = ft_str_to_tokens(input);
	while (*tokens)
	{
		if (ft_str_is_nbr(*tokens))
			ft_stack_add_nbr(stack_nbr, ft_atoi(*tokens));
		if (ft_str_is_op(*tokens)) {
			while (ft_get_op_pres(*tokens) >= ft_get_op_pres(stack_nbr->data))
				ft_stack_add(stack_nbr, ft_stack_pop(stack_op));
		}
		if (ft_strcmp(*tokens, "("))
			ft_stack_add(stack_op, *tokens);
		if (ft_strcmp(*tokens, ")"))
		{
			while (ft_strcmp(stack_op->data, ")"))
				ft_stack_add(stack_nbr, ft_stack_pop(stack_op));
			ft_stack_pop(stack_op);
		}
		tokens++;
	}
	while (ft_stack_size(stack_op))
		ft_stack_add(stack_nbr, ft_stack_pop(stack_op));
	return (result);
}
