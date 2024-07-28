SRC_PATH = .
LIBFT_PATH = libft/
PRINTF_PATH = printf/
LIBFT_SRC := $(wildcard $(LIBFT_PATH)*.c)
PRINTF_SRC = $(wildcard $(PRINTF_PATH)*.c)

CFLAGS = -Wall -Wextra -Werror -Iincludes

# Objects
OBJ_PATH	= obj/
OBJ_LIBFT = $(patsubst $(LIBFT_PATH)%.c, $(OBJ_PATH)%.o, $(LIBFT_SRC))
OBJ_PRINTF = $(patsubst $(PRINTF_PATH)%.c, $(OBJ_PATH)%.o, $(PRINTF_SRC))
OBJ = $(OBJ_LIBFT) $(OBJ_PRINTF)

CC = gcc
RM = rm -f
NAME = libft.a

all: ${NAME}

# Rule to compile .c files to .o files
$(OBJ_PATH)%.o: $(LIBFT_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(PRINTF_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}:	${OBJ}
	ar rc ${NAME} ${OBJ}

$(OBJ): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

clean:
	${RM} -rf $(OBJ_PATH)

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re