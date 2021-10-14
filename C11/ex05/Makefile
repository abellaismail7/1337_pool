CC 		= gcc
CCFLAGS = -Wall -Werror -Wextra -I./includes

FILES 	= do-op ft_nbr ft_operators
SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
EXEC	= do-op
B_DIR	= build
B_OBJ	= $(addprefix $(B_DIR)/, $(OBJ))

all: $(EXEC)

$(EXEC): $(B_OBJ)
	$(CC) $(CCFLAGS) -o $(EXEC) $(B_OBJ)

$(B_DIR)/%.o: %.c 
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(B_OBJ)
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(EXEC)

.PHONY: all clean fclean
