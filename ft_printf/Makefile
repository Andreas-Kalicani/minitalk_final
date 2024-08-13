NAME = libftprintf.a
CC = gcc
TARGETS = ft_print_hex.c ft_print_utils.c ft_printf_pointer.c ft_printf.c ft_unsigned.c ft_print_itoa.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(TARGETS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re