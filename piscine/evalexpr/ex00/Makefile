# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/18 13:35:52 by rbarbero          #+#    #+#              #
#    Updated: 2017/07/19 10:43:29 by rbarbero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op
SRCS = srcs/ft_atoi.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_usage.c \
	   srcs/ft_op.c srcs/ft_putnbr.c srcs/ft_strcmp.c srcs/main.c
INCLUDES = includes/f_opp.h includes/ft.h includes/ft_opp.h includes/t_opp.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	/bin/rm -f $(NAME)
