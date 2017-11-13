# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/18 13:35:52 by rbarbero          #+#    #+#              #
#    Updated: 2017/07/19 10:39:04 by rbarbero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_strcmp.c srcs/ft_swap.c srcs/ft_putstr.c \
	   srcs/ft_strlen.c
#INCLUDES =
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar -rc $(NAME) *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
