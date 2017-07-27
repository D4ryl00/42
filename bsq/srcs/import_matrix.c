/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:04:02 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/26 23:07:26 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/import_matrix.h"
#include "../includes/ft_list.h"
#include "../includes/board.h"
#include "../includes/print.h"

int		list_to_tab(t_board *board, t_list *list, int width)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = 0;
	if (!(board->tab = malloc(sizeof(board->tab) * board->height)))
		return (0);
	while (i < board->height)
		if (!(board->tab[i++] = malloc(sizeof(*(board->tab)) * width)))
			return (0);
	i = width;
	while (--i >= 0)
	{
		board->tab[0][i] = *((char *)list->data);
		list = list->next;
	}
	ft_list_clear(&tmp);
	return (1);
}

int		import_parameters(int fd, t_board *board)
{
	char	line[14];
	int		count;
	int		i;
	int		ret_read;

	count = 0;
	i = -1;
	while ((ret_read = read(fd, &line[count++], 1)))
		if (line[count - 1] == '\n' || count > 13)
			break ;
	if (ret_read < 0 || count < 5 || count > 13)
		return (0);
	count--;
	board->char_full = line[--count];
	board->char_obs = line[--count];
	board->char_empty = line[--count];
	while (++i < count)
		if (line[i] >= '0' && line[i] <= '9')
			board->height = board->height * 10 + (line[i] - '0');
		else
			return (0);
	if (!board->height || board->char_obs == board->char_full || board->char_obs
			== board->char_empty || board->char_full == board->char_empty)
		return (0);
	return (1);
}

int		import_first_line(int fd, t_board *board)
{
	t_list	*list;
	int		ret_read;
	int		count;
	char	buf;
	char	*ptr;

	count = 0;
	while ((ret_read = read(fd, &buf, 1)))
	{
		if ((buf == '\n' && !count) || !(ptr = malloc(sizeof(char))))
			return (0);
		*ptr = buf;
		if (buf == '\n')
			break ;
		else if (count++ == 0)
			list = ft_create_elem(ptr);
		else
			ft_list_push_front(&list, ptr);
	}
	if (ret_read < 0)
		return (0);
	board->width = count;
	if (!list_to_tab(board, list, count))
		return (0);
	return (1);
}

int		import_rest_matrix(int fd, t_board *board)
{
	int		ret_read;
	int		count;
	int		i;
	char	c;

	count = 1;
	i = 0;
	while ((ret_read = read(fd, board->tab[++i], board->width)))
	{
		while (ret_read != board->width)
			ret_read += read(fd, board->tab[i] + ret_read
					, board->width - ret_read);
		read(fd, &c, 1);
		if (c == '\n')
			count++;
		if (c != '\n' || (count == board->height && read(fd, &c, 1) > 0))
			return (0);
		else if (count == board->height)
			break ;
	}
	if (ret_read < 0 || count != board->height)
		return (0);
	if (fd > 0)
		close(fd);
	return (1);
}

t_board	*import_matrix(int ac, char **av, int choice)
{
	t_board		*board;
	int			fd;

	if (!(board = malloc(sizeof(t_board))))
		return (0);
	board->height = 0;
	board->width = 0;
	if (ac < 2)
		fd = 0;
	else if ((fd = open(av[choice], O_RDONLY)) < 0)
		return (0);
	if (!import_parameters(fd, board) || !import_first_line(fd, board)
			|| !import_rest_matrix(fd, board))
		return (0);
	return (board);
}
