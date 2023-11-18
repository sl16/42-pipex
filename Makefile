# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:14:33 by vbartos           #+#    #+#              #
#    Updated: 2023/08/29 10:55:35 by vbartos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT ---------------------------------- #

NAME			= pipex

# FLAGS ------------------------------------ #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

# SOURCE FILES ----------------------------- #

SRCS			= src/pipex.c\
				src/pipex_utils.c\
				libft/libft.a\

#SRCS_BONUS		= src_bonus/pipex.c\
				libft/libft.a\

# COLOURS ---------------------------------- #

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# RULES ------------------------------------ #

all: $(NAME)

$(NAME):
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(GREEN) - Project compiled.$(RESET)"

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	@echo "$(GREEN) - Project binary files deleted.$(RESET)"

clean:
	${RM} ${OBJS}
	make clean -C libft
	@echo "$(GREEN) - Project object files deleted.$(RESET)"

re: fclean all

bonus: clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)
	@echo "$(GREEN) - Project BONUS compiled.$(RESET)"

.PHONY: all clean fclean re bonus