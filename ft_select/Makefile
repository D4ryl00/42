# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 17:30:48 by rbarbero          #+#    #+#              #
#    Updated: 2018/04/16 06:04:48 by rbarbero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCS = main.c signals.c termcaps.c print.c print_top.c items.c row.c \
	   list_items.c print_list.c
SRCS_DIR = srcs/
LIB_DIR = libft

HEADERS = ft_select.h
HEADERS_DIR = includes/
LHEADERS = $(HEADERS:%.h=$(HEADERS_DIR)%.h)

OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): $(OBJS) $(LIB_DIR)/libft.a
	$(CC) -lncurses -o $(NAME) $^

$(LIB_DIR)/libft.a:
	$(MAKE) -C $(LIB_DIR)

$(OBJS): %.o: $(SRCS_DIR)%.c $(LHEADERS)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(LIB_DIR)/includes -o $@ -c $<

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIB_DIR) $@

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) $@

re: fclean all
