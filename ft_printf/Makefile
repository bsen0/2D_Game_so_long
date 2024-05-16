# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 14:07:27 by bsen              #+#    #+#              #
#    Updated: 2024/01/16 14:58:39 by bsen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

C_FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
 ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY : all clean fclean re