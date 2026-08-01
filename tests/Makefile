NAME := unit_test
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC := $(wildcard ../*.c)
TEST_SRC := $(wildcard unit_tests/*.c)
LIBFT_DIR := ../libft

TEST_OBJS := $(patsubst unit_tests/%.c, obj/unit_tests/%.o,$(TEST_SRC))
OBJ := $(patsubst ../%.c, obj/%.o,$(SRC))
OBJS := $(TEST_OBJS) $(OBJ)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -lcriterion

$(LIBFT):
	make -C $(LIBFT_DIR)
obj/%.o: ../%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

obj/unit_tests/%.o: unit_tests/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@
clean:
	rm -rf obj
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re