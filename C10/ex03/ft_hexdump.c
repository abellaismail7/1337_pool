#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "util.h"

int main(int ac, char **av)
{
	int i;

	i = 2;
	if(ac == 1)
		dump_buf(FT_STDIN);
	else if(ac > 1)
	{
		if(!ft_strcmp("-C", av[1]))
		{
			while(i < ac)
				dump_file(av[i++]);
		}
	}
}
