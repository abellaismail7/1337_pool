#ifndef UTIL_H
# define UTIL_H

int	ft_strlen(char *str);
int	tail_file(char *filename, int count);
void	tail_buf(int buf, int count);
int	ft_strcmp(char *s1, char *s2);
int ft_atoi(char *str);

# define FT_STDIN 0
# define FT_ERR_NO_ARG -1
# define FT_ERR_ILLEGAL_OFFSET -2
# define FT_READ_10_LINES -3
#endif
