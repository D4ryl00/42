/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 05:02:05 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/14 10:25:10 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PERSO_H
#	define FT_PERSO_H

#include <string.h>

#define SAVE_AUSTIN_POWERS strdup("spy")

struct	s_perso
{
	char	*name;
	float	life;
	int		age;
	char	*profession;
};

typedef struct s_perso	t_perso;

#	endif
