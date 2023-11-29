# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:08:48 by fdiaz-gu          #+#    #+#              #
#    Updated: 2023/11/29 17:26:50 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
BONSU_DIR = ./src/bonus
SRC = pipex.c utils.c
BONUS_SRC = pipex_bonus.c utils_bonus.c

OBJS = $(addprefix $(SRC_DIR)/,  $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(BONSU_DIR)/, $(BONUS_SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
AR = ar
ARGFAGS = rcs
RM = rm -rf

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

NAME = pipex
B_NAME = pipex_bonus

all: $(NAME)
$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

B = .

$(B_NAME): $(BONUS_OBJS)		
	@make bonus -C $(LIBFT_DIR)	
	@gcc $(CFLAGS) $(BONUS_OBJS)  $(LIBFT) -o $(B_NAME)	

bonus: $(B)

$(B): $(B_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(LIBFT_A)

fclean: clean
	$(RM) $(NAME) $(B_NAME) $(OBJS)
	make -C $(LIBFT_DIR) fclean

re: fclean
	@make all

.PHONY: all clean fclean re