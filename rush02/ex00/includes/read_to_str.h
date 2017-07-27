/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_str.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:39:23 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/22 18:16:25 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_TO_STR_H
# define READ_TO_STR_H

typedef	struct		s_list
{
	struct s_list	*next;
	char			data;
}					t_list;

char				*read_to_str(void);

#endif
