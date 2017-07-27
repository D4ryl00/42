# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchojnac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 22:46:10 by gchojnac          #+#    #+#              #
#    Updated: 2017/07/26 11:56:31 by gchojnac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq
SRC_P	=	$(shell ls srcs/)
SRC		=	$(addprefix srcs/, $(SRC_P))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RED		=	\033[1;31m
GREEN	=	\033[1;32m
NC		=	\033[0m

.PHONY	= all clean re clean-debug clean-maps fclean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "[$(GREEN)✓$(NC)] Sources of $(NAME) compiled"
	@echo "[$(GREEN)✓$(NC)] Executable $(NAME) built"

debug:
	@$(CC) -g $(SRC) -o debug.out
	@echo "[$(GREEN)✓$(NC)] Sources of $(NAME) compiled"
	@echo "[$(GREEN)✓$(NC)] Debugger executable debug.out built"
	@echo "[$(GREEN)✓$(NC)] Debugger directory debug.out.dSYM added"	

clean-debug:
	@rm -Rdf debug.out.dSYM
	@rm -Rf debug.out
	@echo "[$(RED)-$(NC)] Executable debug.out cleaned"
	@echo "[$(RED)-$(NC)] Directory debug.out.dSYM cleaned"

clean-maps:
	@rm -Rf *.map
	@rm -Rf *.res
	@echo "[$(RED)-$(NC)] Maps cleaned"
	@echo "[$(RED)-$(NC)] Results cleaned"

clean:
	@rm -Rf $(NAME)
	@echo "[$(RED)-$(NC)] Executable $(NAME) cleaned"

fclean: clean clean-debug clean-maps

re: clean all
