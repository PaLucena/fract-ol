NAME = fractol

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
SEGFAULT_FLAG = -fsanitize=address  # para ver donde hay segmentation fault #
RM = rm -rf

SRC_PATH = src/
SRC = main.c hooks.c fractal.c image.c
OBJ_PATH = objs/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

BREW = "/Users/$(USER)/.brew/opt/glfw/lib/"
INC = -I includes/libft
MLX = includes/MLX42/libmlx42.a


all: libft $(NAME)

bonus: libft $(NAME_BONUS)

$(NAME): libft mlx $(OBJ)
	@ gcc $(SEGFAULT_FLAG) $(CFLAGS) $(OBJ) $(MLX) -lglfw -L $(BREW) $(INC) -o $(NAME) $(LIBFT)
	@ echo "\n\t\t\033[32m----Fractol compiled----\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_BONUS_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@

libft:
	@ make -C includes/libft/

mlx:
	@make -C includes/MLX42/

re: fclean all

re_bonus: fclean bonus

clean:
	@ $(RM) -r $(OBJ_PATH)
	@ make -C includes/libft/ clean
	@ echo "\n\t\t\033[31m----Deleting everything----\n"

fclean: clean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@ make -C includes/libft/ fclean
	@ make -C includes/MLX42/ fclean

.PHONY: all bonus libft mlx re re_bonus clean fclean