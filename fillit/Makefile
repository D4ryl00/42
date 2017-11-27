# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 18:12:30 by rbarbero          #+#    #+#              #
#    Updated: 2017/11/25 10:41:53 by rbarbero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c print.c parse.c resolve.c ft_read.c invalid_tetri.c
HEADERS = fillit.h
OBJS = $(SRCS:%.c=%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): libft/libft.a $(OBJS)
	$(CC) -o $(NAME) $^

libft/libft.a:
	$(MAKE) -C libft

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)
	@$(MAKE) -C libft $@

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C libft $@

re: fclean all
