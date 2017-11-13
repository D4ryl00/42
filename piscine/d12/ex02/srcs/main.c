/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:13:21 by rbarbero          #+#    #+#             */
/*   Updated: 2017/10/09 23:37:52 by rbarbero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "../includes/line_args.h"
#include "../includes/opt.h"
#include "../includes/errors.h"

t_line_args	*get_line_args(int ac, char **av)
{
	t_line_args	*line_args;
	int			opt_nbr;

	opt_nbr = 2;
	line_args = line_args_init(opt_nbr, ac);
	if (opt_add(line_args, 'c', "cc", mandatory))
	{
		print_err("Error in get_line_args: add");
		return (0);
	}
	if (opt_add(line_args, 'f', "ff", flag))
	{
		print_err("Error in get_line_args: add");
		return (0);
	}
	if (line_args_parsing(line_args, ac, av))
	{
		print_err("Error in get_line_args: parsing");
		return (0);
	}
	return (line_args);
}
#include <stdio.h>
int			main(int argc, char **argv)
{
	//int			i;
	t_line_args	*line_args;
	//int			fd;
	//char		buf[4096];
	//int			ret;
	char		**p;

	//i = 0;
	if (!(line_args = get_line_args(argc, argv)))
		return (1);
	printf("name: %s, value: %s\n\
			name: %s, value: %s\n", line_args->opt_values[0].l_name, line_args->opt_values[0].value, line_args->opt_values[1].l_name, line_args->opt_values[1].value);
	p = line_args->arg_values;
	while (*p)
		printf("arg: %s\n", *p++);
	/*while (++i < argc)
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
	}*/
	return (0);
}
