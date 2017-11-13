/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 10:08:17 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/16 23:04:26 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 && *s2 != '*')
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
	{
		return ((*s1 ? match(s1 + 1, s2) : 0)
				|| match(s1, s2 + 1));
	}
	return (0);
}