#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "util.h"

char g_buf[29000];
void read_from_stdin()
{
	char c;
	int i;

	i = 0;
	while(read(FT_STDIN, &c, 1))
		g_buf[i++] = c;

	write(1, g_buf, i);
}

int get_count(int ac, char **av)
{
	if (ac < 3)
		return FT_ERR_NO_ARG;
	if(!ft_strcmp("-c",av[1]))
	{
		return ft_atoi(av[2]);
	}
	return 0;
}

int main(int ac, char **av)
{
	int i;
	int count;

	count = 0;
	if(ac == 1)
		tail_buf(FT_STDIN,-1);
	else if(ac > 1)
	{
		count = get_count(ac, av);
		if(count == FT_ERR_ILLEGAL_OFFSET)
		{
			// invalid number;
		}
		else if(count == FT_ERR_NO_ARG)
		{
			// no arg for -c
		}
		else {
			i = 3;
			while(av[i])
				tail_file(av[i++], count);
		}
	}
}
