# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 15:56:07 by bsengeze          #+#    #+#              #
#    Updated: 2023/07/29 20:23:06 by bsengeze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
INCLUDE = -I./include -I./libft/include
GREEN   = \033[32;1m
RESET	= \033[0m
SRC_DIR = srcs/
OBJ_DIR = objs/

SRCS = pipex.c utils.c
SRC	= $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

SRCS_BONUS = pipex_bonus.c utils_bonus.c utils.c
SRC_BONUS = $(addprefix $(SRC_DIR), $(SRCS_BONUS))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(notdir $(SRC_BONUS:.c=.o)))

all:	$(NAME) 

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN) pipex compiled with $(CFLAGS)$(RESET)"

bonus:	$(NAME_BONUS) 

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)
	@echo "$(GREEN) pipex_bonus compiled with $(CFLAGS)$(RESET)"

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
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(GREEN) Full cleaned $(RESET)"

re:	fclean all

re_bonus:	fclean all

.PHONY: all clean fclean re bonus re_bonus