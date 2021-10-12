#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i= 0;
	while(str[i])
		i++;
	return i;
}

int print_file(char *filename)
{
	int fp;
	char c;
	char *str;

	fp = open(filename, O_RDWR);
	if (errno)
	{
		str = strerror(errno);
		write(1, "ft_cat: ", 8);
		write(1, filename, ft_strlen(filename));
		write(1, ": ", 2);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		errno = 0;
		return 1;
	}
	if (fp < 0)
		return 1;

	while(read(fp, &c, 1))
		write(1, &c, 1);
	close(fp);
	return 0;
}
