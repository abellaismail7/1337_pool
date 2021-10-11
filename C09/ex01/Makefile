CC 		= gcc
CCFLAGS = -Wall -Wextra -Werror
HEADER	= -I./includes/
OBJ_PATH = srcs/
FILES 	= ft_putchar ft_swap ft_putstr ft_strlen ft_strcmp
SRC		= $(addprefix $(OBJ_PATH), $(FILES:=.c))
OBJ		= $(addprefix $(OBJ_PATH), $(FILES:=.o))
LIBFT	= libft.a

all: $(LIBFT)

$(LIBFT): $(OBJ)
	ar rc $(LIBFT) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< $(HEADER) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
