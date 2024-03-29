# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 15:38:27 by mmanouze          #+#    #+#              #
#    Updated: 2022/04/08 15:43:22 by mmanouze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c other_utils.c map_errors.c ft_split.c ft_printf.c \
        get_next_line.c get_next_line_utils.c ft_itoa.c ft_error.c graph_map.c moves.c \

OBJ = $(SRCS:.c=.o)
MLX_FLAGS    = -lmlx -framework OpenGL -framework Appkit


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : clean all fclean re bonus