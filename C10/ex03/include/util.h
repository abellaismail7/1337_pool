#ifndef UTIL_H
# define UTIL_H

void	dump_files(char **files, int size);
void	dump_buf(int bufnb);

# define FT_STDIN 0
# define FT_ERR_NO_ARG -1
# define FT_ERR_ILLEGAL_OFFSET -2
# define FT_READ_10_LINES -3
#endif
