NAME = test_print
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ../../libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(wildcard ../../*.c)
TEST_SRC = printf_test.c

OBJ := $(patsubst ../../%.c,obj/%.o,$(SRC))
TEST_OBJS := $(patsubst %.c,obj/print/%.o,$(TEST_SRC))

OBJS := $(OBJ) $(TEST_OBJS)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
$(LIBFT):
	make -C $(LIBFT_DIR)
obj/%.o: ../../%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

obj/print/%.o: %.c
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