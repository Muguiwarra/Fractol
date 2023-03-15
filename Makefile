# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabboune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 01:04:10 by nabboune          #+#    #+#              #
#    Updated: 2023/03/14 22:18:24 by nabboune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft.a

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =	fractol.c \
		fractals.c \
		zoom.c \
		mlx_help.c

# SRCS_BONUS =

OBJS = $(SRCS:.c=.o)

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.o: .c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFT) $(OBJS)

$(LIBFT) :
	cd Libft/ && $(MAKE)

# $(CHECKER) : $(LIBFT) $(OBJS_BONUS)
# 	$(CC) $(CFLAGS) -o $(CHECKER) $(LIBFT) $(OBJS_BONUS)

all : $(NAME)

# bonus : $(CHECKER)

clean :
	cd Libft && $(MAKE) clean && cd .. && $(RM) $(OBJS) libft.a

fclean : clean
	cd Libft && $(MAKE) fclean && cd .. && $(RM) $(LIBFT) $(NAME) $(CHECKER)

re : fclean all

.PHONY : all clean fclean re
