#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "util.h"

void read_from_user()
{
	int i;
	char c;

	i = 0;
	while(1)
	{
		while(!read(FT_STDIN, &c, 1));
		write(1, &c, 1);
	}
}

void read_from_stdin()
{
	char c;
	int stdin_is_empty;

	stdin_is_empty = 1;
	while(read(FT_STDIN, &c, 1))
	{
		stdin_is_empty = 0;
		write(1, &c, 1);	
	}
	if(stdin_is_empty)
		read_from_user();
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
			else if (!print_file(av[i]))
			{
				write(1, "cat: ", 5);
				write(1, av[i], ft_strlen(av[i]));
				write(1, " Cannot read file.\n", 19);
			}
			i++;
		}
	}
}
