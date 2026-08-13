NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJS = $(wildcard $(LIBFT_DIR)/*.o)

SRC = \
	ft_printf.c \
	ft_putnbr.c \
	ft_printstr.c \
	ft_printchar.c \
	ft_printpercent.c \
	ft_printunsignednum.c \
	ft_printptr.c \
	print_hex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
