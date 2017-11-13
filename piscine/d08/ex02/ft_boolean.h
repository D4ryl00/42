/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:40:14 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/17 17:29:06 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define FALSE 0
# define TRUE 1
# define SUCCESS 0
# define EVEN(x) ((x) % 2 ? 0 : 1)
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

typedef	int	t_bool;

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif
