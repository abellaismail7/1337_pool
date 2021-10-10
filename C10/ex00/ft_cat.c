#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "util.h"

void read_from_stdin()
{
	char c;
	while(read(FT_STDIN, &c, 1))
		write(1, &c, 1);	
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
			{
				if(!stdin_done)
					read_from_stdin();
				stdin_done = 1;
			}
			else
				print_file(av[i]);
			i++;
		}
	}
}
