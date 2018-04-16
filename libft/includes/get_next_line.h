/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 09:23:35 by rbarbero          #+#    #+#             */
/*   Updated: 2017/12/18 15:34:36 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096

# include "libft.h"

typedef struct s_list	t_list;

typedef struct	s_buf
{
	int				fd;
	t_list			*lchar;
	unsigned int	count_nl;
}				t_buf;

int				get_next_line(const int fd, char **line);

#endif
