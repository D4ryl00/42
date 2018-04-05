# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 17:30:48 by rbarbero          #+#    #+#              #
#    Updated: 2018/04/04 13:56:33 by rbarbero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = main.c error.c args.c args_options.c args_options2.c list.c \
	   delete.c load_dirs.c stats.c row.c printl_attributes.c date.c \
	   printl_max_width.c printl.c color.c sorts.c print.c file_u_perm.c \
	   file_g_perm.c file_o_perm.c
SRCS_DIR = srcs/
LIB_DIR = libft

HEADERS = ft_ls.h
HEADERS_DIR = includes/
LHEADERS = $(HEADERS:%.h=$(HEADERS_DIR)%.h)

OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

debug: CFLAGS += -g
debug: all

test:
	gcc -Wall -Wextra test.c -I includes -L . -lftprintf -g

$(NAME): $(OBJS) $(LIB_DIR)/libft.a
	$(CC) -o $(NAME) $^

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
