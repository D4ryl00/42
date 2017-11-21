# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:33:27 by rbarbero          #+#    #+#              #
#    Updated: 2017/11/08 15:26:53 by rbarbero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRCS_DIR = srcs/
SRCS = main.c
INCLUDES =
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	gcc  -o $(NAME) $^

$(OBJS): %.o : $(SRCS_DIR)%.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
