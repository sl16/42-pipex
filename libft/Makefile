# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:14:33 by vbartos           #+#    #+#              #
#    Updated: 2023/07/28 13:30:30 by vbartos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT ---------------------------------- #

NAME			= libft.a

# FLAGS ------------------------------------ #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
IFLAGS			= -Ilibft -Ift_printf -Iget_next_line
RM				= rm -rf

# SOURCE FILES ----------------------------- #

SRCS			= libft/ft_atoi.c\
				libft/ft_bzero.c\
				libft/ft_isalnum.c\
				libft/ft_isalpha.c\
				libft/ft_isascii.c\
				libft/ft_isdigit.c\
				libft/ft_isprint.c\
				libft/ft_memchr.c\
				libft/ft_memcmp.c\
				libft/ft_memcpy.c\
				libft/ft_memmove.c\
				libft/ft_memset.c\
				libft/ft_strchr.c\
				libft/ft_strdup.c\
				libft/ft_strlcat.c\
				libft/ft_strlcpy.c\
				libft/ft_strlen.c\
				libft/ft_strncmp.c\
				libft/ft_strnstr.c\
				libft/ft_strrchr.c\
				libft/ft_tolower.c\
				libft/ft_toupper.c\
				libft/ft_calloc.c\
				libft/ft_substr.c\
				libft/ft_strjoin.c\
				libft/ft_itoa.c\
				libft/ft_split.c\
				libft/ft_strtrim.c\
				libft/ft_strmapi.c\
				libft/ft_striteri.c\
				libft/ft_putchar_fd.c\
				libft/ft_putstr_fd.c\
				libft/ft_putendl_fd.c\
				libft/ft_putnbr_fd.c\
				libft/ft_lstadd_back.c\
				libft/ft_lstadd_front.c\
				libft/ft_lstclear.c\
				libft/ft_lstdelone.c\
				libft/ft_lstiter.c\
				libft/ft_lstlast.c\
				libft/ft_lstmap.c\
				libft/ft_lstnew.c\
				libft/ft_lstsize.c\
				\
				ft_printf/ft_printf.c\
				ft_printf/ft_sort.c\
				ft_printf/ft_putchar.c\
				ft_printf/ft_putnbr.c\
				ft_printf/ft_putstr.c\
				ft_printf/ft_putunsigned.c\
				ft_printf/ft_hexadec.c\
				ft_printf/ft_putptr.c\
				\
				get_next_line/get_next_line.c\

OBJS = ${SRCS:.c=.o}

# COLOURS ---------------------------------- #

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# RULES ------------------------------------ #

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN) - Libft compiled.$(RESET)"

.c.o:
	@${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o} ${IFLAGS} 

clean:
	${RM} ${OBJS}
	@echo "$(GREEN) - Libft object files removed.$(RESET)"

fclean: clean
	${RM} $(NAME)
	@echo "$(GREEN) - Libft binary files removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re