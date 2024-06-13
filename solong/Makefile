# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:23:41 by bsen              #+#    #+#              #
#    Updated: 2024/05/29 16:59:23 by bsen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC =	src/map_control.c \
		src/map_control2.c\
		src/so_long.c\
		src/utils.c\
		src/map_control3.c

LIBFT			=	libft/libft.a
LIBFT_PATH		=	libft

MINILIBX_PATH		=	minilibx
MLX				=	$(MINILIBX_PATH)/libmlx.a
OBJ				=	$(SRC:.c=.o)
all:	$(NAME)

$(NAME): $(MLX) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX):
	make -C $(MINILIBX_PATH) all

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean


fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:	all clean fclean re libft
