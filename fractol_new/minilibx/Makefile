#ECHO COLORS
NOC=\033[0m
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "$(GREEN) ✓ MINILIBX: Created Object files$(NOC)"
	@echo "$(GREEN) ✓ MINILIBX: Created $(NOM)$(NOC)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED) ✗ MINILIBX: Removed Object files$(NOC)"

fclean: clean
	@rm -f $(NOM)
	@rm -f mlx_app
	@echo "$(RED) ✗ MINILIBX: Removed $(NOM)$(NOC)"

re: fclean all

.SILENT: all clean re

.PHONY: re