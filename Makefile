NAME = libftprintf.a
CC = cc
CgFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c ft_putnbr.c ft_printstr.c ft_printchar.c ft_printpercent.c	\
		ft_printunsignednum.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean r
