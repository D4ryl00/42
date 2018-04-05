/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:05:43 by rbarbero          #+#    #+#             */
/*   Updated: 2018/04/04 13:03:28 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

void	delete_file(void *content, size_t size)
{
	t_file	*file;

	(void)size;
	file = content;
	if (file->name)
		free(file->name);
	if (file->path)
		free(file->path);
	if (file->stats)
		free(file->stats);
	free(content);
}

void	delete_dir(void *content, size_t size)
{
	(void)size;
	free(content);
}
