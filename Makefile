NAME = fractol
#NAME_BONUS = pipex_bonus

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Imlx -Lmlx/ -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

SRC_PATH = src/
SRC = main.c window.c
OBJ_PATH = objs/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

#SRC_BONUS_PATH = src/
#SRC_BONUS = pipex_bonus.c pipex_utils.c
#OBJ_BONUS = $(addprefix $(OBJ_PATH), $(SRC_BONUS:.c=.o))


all: libft $(NAME)

bonus: libft $(NAME_BONUS)

$(NAME): $(OBJ)
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJ) includes/libft/libft.a $(MLX_FLAGS) 
	@ echo "\n\t\t\033[32m----Fractol compiled----\n"

#$(NAME_BONUS): $(OBJ_BONUS)
#	@ $(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) libft/*.o
#	@ echo "\n\t\t\033[32m----Pipex_bonus compiled----\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_BONUS_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@

libft:
	@ make -C includes/libft/

re: fclean all

re_bonus: fclean bonus

clean:
	@ $(RM) -r $(OBJ_PATH)
	@ make -C includes/libft/ clean
	@ echo "\n\t\t\033[31m----Deleting everything----\n"

fclean: clean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@ make -C includes/libft/ fclean

.PHONY: all bonus libft re re_bonus clean fclean