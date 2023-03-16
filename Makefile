# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabboune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 01:04:10 by nabboune          #+#    #+#              #
#    Updated: 2023/03/16 09:02:42 by nabboune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =	fractol.c \
		fractals.c \
		magie.c \
		zoom.c \
		mlx_help.c \
		help.c

OBJS = $(SRCS:.c=.o)

.o: .c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFT) $(OBJS) && clear

$(LIBFT) :
	cd Libft/ && $(MAKE)

all : $(NAME)

clean :
	cd Libft && $(MAKE) clean && cd .. && $(RM) $(OBJS) libft.a && clear

fclean : clean
	cd Libft && $(MAKE) fclean && cd .. && $(RM) $(LIBFT) $(NAME) $(CHECKER) && clear

re : fclean all

.PHONY : all clean fclean re
