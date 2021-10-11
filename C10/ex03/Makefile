CC 		= gcc
CCFLAGS = -Wall -Werror -Wextra -I./include

FILES 	= ft_hexdump util
SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
EXEC	= ft_hexdump
B_DIR	= build
B_OBJ	= $(addprefix $(B_DIR)/, $(OBJ))

all: $(EXEC)

$(EXEC): $(B_OBJ)
	$(CC) $(CCFLAGS) -o $(EXEC) $(B_OBJ)

$(B_DIR)/%.o: %.c 
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	rm $(B_OBJ)

fclean: clean
	rm $(EXEC)

.PHONY: all clean fclean all
