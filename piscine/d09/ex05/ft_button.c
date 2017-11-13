/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:34:09 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/13 22:50:02 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_button(int i, int j, int k)
{
	if (i <= j && j <= k)
		return (j);
	else if (j <= k && k <= i)
		return (k);
	else if (k <= i && i <= j)
		return (i);
	else if (j <= i && i <= k)
		return (i);
	else if (i <= k && k <= j)
		return (k);
	else
		return (j);
}
