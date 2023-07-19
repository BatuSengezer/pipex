# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 16:30:24 by bsengeze          #+#    #+#              #
#    Updated: 2023/07/02 22:14:20 by bsengeze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIB = ar -rcs
RM	 = /bin/rm -f

NAME = libft.a
HDRS = libft.h
OBJ_DIR = objs/

SRCS = 	ft_isalpha.c ft_isdigit.c ft_issign.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putchar.c ft_putstr.c \
		get_next_line.c get_next_line_utils.c

OBJ	= $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all:	$(OBJ_DIR)	$(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(NAME):	$(OBJS) $(HDRS)
			$(LIB) $(NAME) $(OBJS)

clean:
		rm -rf $(OBJ_DIR)
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)	

re:	fclean all

.PHONY: all clean fclean re

