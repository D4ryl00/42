/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:37:23 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/08 15:28:30 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

void	ft_perror(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[2048];
	int		ret;

	if (argc < 2)
	{
		ft_perror("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_perror("Too many arguments.\n");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buf, 2048)))
	{
		if (ret < 0)
			return (1);
		write(1, buf, ret);
	}
	close(fd);
}
