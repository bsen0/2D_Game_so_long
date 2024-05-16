# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:23:41 by bsen              #+#    #+#              #
#    Updated: 2024/05/14 16:04:36 by bsen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	cc
CFLAGS			=	-g -Wall -Wextra -Werror
RM				=	rm -rf

SRC =	src/map_control.c \
		src/map_control2.c\
		src/so_long.c\
		src/utils.c

OBJ = $(SRC:.c=.o)
LIBFT			=	libft/libft.a





all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o so_long


$(LIBFT):
	make -C libft

c:
	rm -rf $(OBJ)
	rm -rf $(NAME)
