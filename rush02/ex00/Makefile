# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/21 11:16:53 by kjalloul          #+#    #+#              #
#    Updated: 2017/07/23 01:32:17 by kjalloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

SRC = 	srcs/check_if_rectangle.c\
		srcs/colle2.c\
		srcs/ft_tools.c\
		srcs/main.c\
		srcs/read_to_str.c\
		srcs/rush.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	/bin/rm -f 	check_if_rectangle.c\
				colle2.o\
				ft_tools.o\
				main.o\
				read_to_str.o\
				rush.o


fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
