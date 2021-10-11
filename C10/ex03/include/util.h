#ifndef UTIL_H
# define UTIL_H

int	ft_strlen(char *str);
int	dump_file(char *filename);
void	dump_buf(int bufnb);
int	ft_strcmp(char *s1, char *s2);
int ft_atoi(char *str);

# define FT_STDIN 0
# define FT_ERR_NO_ARG -1
# define FT_ERR_ILLEGAL_OFFSET -2
# define FT_READ_10_LINES -3
#endif
