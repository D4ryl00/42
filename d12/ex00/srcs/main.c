/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 02:00:40 by rbarbero          #+#    #+#             */
/*   Updated: 2017/07/21 09:23:03 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../includes/main.h"

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *str)
{
	while (*str)
		ft_putchar(fd, *str++);
}

int		ft_print_errors(int nbr)
{
	if (nbr == 0)
		ft_putstr(2, "File name missing.\n");
	else if (nbr == 1)
		ft_putstr(2, "Too many arguments.\n");
	else if (nbr == 2)
		ft_putstr(2, "File cannot be opened.\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (argc == 1)
		return (ft_print_errors(0));
	if (argc > 2)
		return (ft_print_errors(1));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_print_errors(2));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(1, buf);
	}
	if (close(fd) == -1)
		return (ft_print_errors(3));
}
