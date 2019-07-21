# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 20:05:48 by bcastro           #+#    #+#              #
#    Updated: 2019/07/20 19:24:01 by bcastro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./libft
MINILIBX_DIR  = ./minilibx
SRCS = ./src/main.c ./src/parse.c ./src/error.c
LIBS = ./minilibx/libmlx.a ./libft/libft.a

#ECHO COLORS
NOC=\033[0m
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m

all:
	@echo "LIBFT:"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "MINILIBX:"
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo "FDF:"
	@gcc -Wall -Wextra -Werror $(SRCS) $(LIBS) -framework OpenGL -framework AppKit -o fractol
	@echo "$(GREEN) ✓ Fractol: Created executable 'fractol' $(NOC)"

re: fclean all

clean: 
	@echo ""
	@make clean -s -C $(LIBFT_DIR)
	@echo ""
	@make clean -s -C $(MINILIBX_DIR)
	@echo ""

fclean:
	@rm fractol
	@make fclean -s -C $(LIBFT_DIR)
	@make fclean -s -C $(MINILIBX_DIR)
	@echo "$(RED) ✗ Fractol: Removed compiled fractol file $(NOC)"

speed:
	@time ./fractol

.PHONY: re

