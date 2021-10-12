#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "util.h"

char g_buf[30000];

void read_from_stdin()
{
	char c;
	int  i = 0;

	while(read(FT_STDIN, &c, 1))
		g_buf[i++] = c;
	g_buf[i] = 0;
	write(1, g_buf, ft_strlen(g_buf));
}

int main(int ac, char **av)
{
	int i;
	int stdin_done;

	if(ac == 1)
		read_from_stdin();
	else if(ac > 1)
	{
		i = 1;
		stdin_done = 0;
		while(av[i])
		{
			if(*av[i] == '-' && !av[i][1])
				read_from_stdin();
			else
				print_file(av[i]);
			i++;
		}
	}
}
