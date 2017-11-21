# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 18:12:30 by rbarbero          #+#    #+#              #
#    Updated: 2017/11/20 19:42:46 by rbarbero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c print.c
OBJS = $(SRCS:%.c=%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

debug: CFLAGS += -g
debug: all

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	$(CC) -o $(NAME) $^

libft.a:
	$(MAKE) -C libft

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
