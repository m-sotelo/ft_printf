NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_conversion.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

AR = ar rcs

all: $(NAME)
	
$(NAME): $(OBJ)
	$(AR)	$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

