files="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"
obj_files=$(echo $files | sed 's/\.c/.o/g')

gcc -Wall -Werror -Wextra -c $files

ar rcs libft.a $obj_files
