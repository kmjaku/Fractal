# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 18:26:16 by kmjaku            #+#    #+#              #
#    Updated: 2017/04/08 03:42:53 by kmjaku           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol

FLAGS= -Wall -Werror -Wextra

FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT= ./libft/libft.a

SRCS= srcs/burning_ship.c \
	  srcs/draw.c \
	  srcs/hook.c \
	  srcs/julia.c \
	  srcs/main.c \
	  srcs/mandelbrot.c \
	  srcs/utils.c \

OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@echo "\nexecutable fractol is ready"
	@make -C LIBFT
	@gcc -o $(NAME) $(OBJ) $(LIBFT) $(FLAGS) $(FLAGS_MLX)

all: $(NAME)

clean:
	@echo "\nremoving all extensions '.o' in srcs/"
	@rm -rf $(OBJ)
	@echo "clean done for fractol"

fclean: clean
	@echo "\nremoving fractol"
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "fclean is done"

re:
	@echo "removing executable fractol"
	$(clean)
	@make -C libft/ re
	@echo "re-executing all"
	$(all)

.PHONY: clean fclean
