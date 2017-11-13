# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/22 23:12:32 by rbarbero          #+#    #+#              #
#    Updated: 2017/10/12 01:02:19 by rbarbero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
SRCS_DIR = srcs/
SRCS = main.c line_args.c opt.c opt_check.c opt_get.c opt_set.c errors.c\
	   ft_string.c
BUILD_DIR = build/
OBJ = $(SRCS:%.c=$(BUILD_DIR)%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =

all: $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

debug: CFLAGS += -g
debug: all

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $^

$(OBJ): $(BUILD_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(BUILD_DIR)*.o 
	rm -fr $(BUILD_DIR) 

fclean: clean
	rm -f $(NAME)
