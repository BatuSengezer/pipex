# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 15:56:07 by bsengeze          #+#    #+#              #
#    Updated: 2023/07/27 15:56:15 by bsengeze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
INCLUDE = -I./include -I./libft/include
GREEN   = \033[32;1m
RESET	= \033[0m
SRC_DIR = srcs/
OBJ_DIR = objs/

SRCS =	pipex.c utils.c

SRC	= $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all:	$(NAME) 

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN) Pipex compiled with $(CFLAGS)$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft
	@echo "$(GREEN) Libft compiled $(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean: 
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN) Cleaned $(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
	@echo "$(GREEN) Full cleaned $(RESET)"

re:	fclean all

.PHONY: all clean fclean re