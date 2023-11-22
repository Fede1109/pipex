# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:08:48 by fdiaz-gu          #+#    #+#              #
#    Updated: 2023/11/22 15:38:13 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
SRC = pipex.c utils.c

OBJS = $(addprefix $(SRC_DIR)/,  $(SRC:.c=.o))
# BONUS_OBJS
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
AR = ar
ARGFAGS = rcs
RM = rm -rf

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

NAME = pipex

all: $(NAME)
$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

B = .

clean:
	$(RM) $(OBJS) $(LIBFT_A)

fclean: clean
	$(RM) $(NAME) $(OBJS)
	make -C $(LIBFT_DIR) fclean

re: fclean
	@make all

.PHONY: all clean fclean re