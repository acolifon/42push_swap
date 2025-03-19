NAME = push_swap

NAME_BONUS = push_swap_bonus

CC = cc
C_FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = -I ./includes
HEADER_BONUS = -I ./includes/bonus

SRC = src/main.c \
		src/clean_lst.c \
		src/handle_errors.c \
		src/handle_lst.c \
		src/validate_nbrs.c \
		src/op_push.c \
		src/op_rotate.c \
		src/op_rotate_rev.c \
		src/op_swap.c \
		src/sort_stack.c \
		src/update_node.c \

SRC_BONUS = src/bonus/main.c

OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus

OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst src/bonus/%.c, $(OBJ_DIR_BONUS)/%.o, $(SRC_BONUS))

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(C_FLAGS) -o $@ -c $< $(HEADER)

bonus : $(NAME_BONUS) $(LIBFT)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(C_FLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: src/bonus/%.C
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(C_FLAGS) -c $< -o $@ $(HEADER_BONUS)

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus