NAME = fractol

# Compiler
CC = gcc
CFLAGS = -Werror -Wextra -Wall

# Minilibx
MLX_PATH = mlx/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC = -I ./includes/ \
      -I ./libft/includes/ \
      -I ./libft/ \
      -I ./ft_printf \
      -I ./mlx/

# Sources
SRC_PATH = src/
SRC = commands/commands.c \
      events/events.c \
      fractal/complex.c \
      fractal/fractal.c \
      utils/atod.c \
      main.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH = obj/
OBJS = $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRCS))

# Create directories for object files
DIRS = $(OBJ_PATH)commands $(OBJ_PATH)events $(OBJ_PATH)fractal $(OBJ_PATH)utils

all: $(DIRS) $(MLX) $(LIBFT) $(NAME)

# Create necessary directories
$(DIRS):
	@mkdir -p $(DIRS)

# Compile object files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo "Compiled $< to $@"

# Link the final executable
$(NAME): $(OBJS) $(MLX) $(LIBFT)
	@echo "Linking fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) -lXext -lX11 -lm
	@echo "Fractol ready."

# Build MiniLibX
$(MLX):
	@echo "Building MiniLibX..."
	@make -sC $(MLX_PATH)

# Build libft
$(LIBFT):
	@echo "Building libft..."
	@make -sC $(LIBFT_PATH)

# Clean object files
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

# Full clean
fclean: clean
	@echo "Removing fractol executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

# Rebuild everything
re: fclean all

.PHONY: all re clean fclean
