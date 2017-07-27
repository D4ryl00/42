/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:43:33 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/23 01:37:32 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_to_str.h"
#include "../includes/ft_tools.h"
#include "../includes/check_if_rectangle.h"
#include "../includes/colle2.h"
#include "../includes/rush.h"

t_pattern	*init(void)
{
	t_pattern	*tests;
	t_pattern	*ptr;
	int			i;

	tests = malloc(sizeof(t_pattern) * (5 + 1));
	ptr = tests;
	i = 0;
	while (i++ < 5)
	{
		ptr->name = malloc(sizeof(char) * (8 + 1));
		ptr++->pattern = malloc(sizeof(char) * (7 + 1));
	}
	ptr = 0;
	ft_strcpy(tests[0].name, "colle-00");
	ft_strcpy(tests[0].pattern, "o-o|o-o");
	ft_strcpy(tests[1].name, "colle-01");
	ft_strcpy(tests[1].pattern, "/*\\*\\*/");
	ft_strcpy(tests[2].name, "colle-02");
	ft_strcpy(tests[2].pattern, "ABABCBC");
	ft_strcpy(tests[3].name, "colle-03");
	ft_strcpy(tests[3].pattern, "ABCBABC");
	ft_strcpy(tests[4].name, "colle-04");
	ft_strcpy(tests[4].pattern, "ABCBCBA");
	return (tests);
}

void		free_patterns(t_pattern *ptr, t_rect_size *rect)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		free(ptr[i].name);
		free(ptr[i].pattern);
	}
	free(ptr);
	free(rect);
}

int			colle2(void)
{
	char		*input;
	int			i;
	int			flag;
	t_rect_size	*rect;
	t_pattern	*tests;

	i = -1;
	flag = 0;
	tests = init();
	input = read_to_str();
	rect = check_and_count(input);
	if (!rect->is_rectangle)
		return (-1);
	while (++i < 5)
	{
		if (rush_is_valid(input, rect->x, rect->y, tests[i].pattern))
		{
			if (flag)
				ft_putstr("  ||  ");
			ft_print(tests[i].name, rect->x, rect->y);
			flag = 1;
		}
	}
	free_patterns(tests, rect);
	return (flag ? 0 : -1);
}
