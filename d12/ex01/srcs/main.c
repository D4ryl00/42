/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 01:23:49 by rbarbero          #+#    #+#             */
/*   Updated: 2017/08/21 02:35:48 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "../includes/main.h"

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	buf[BUFSIZE];
	int		ret;

	i = 0;
	while (++i < argc || (argc == 1 && i == 1))
	{
		if (argc == 1 || (argv[i][0] == '-' && !argv[i][1]))
			fd = 0;
		else
			fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			return (1);
		ret = 0;
		while ((ret = read(fd, buf, BUFSIZE)))
			if (write(1, &buf, ret) < 0)
				return (1);
		if (fd > 2 && close(fd) < 0)
			return (1);
	}
	return (0);
}
