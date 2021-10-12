#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "util.h"
#include "ft_str.h"

int main(int ac, char **av)
{
	int i;

	i = 2;
	if(ac < 3)
		dump_buf(FT_STDIN);
	else if(ac > 1)
	{
		if(ft_strcmp("-C", av[1]) == 0)
		{
			dump_files(av + 2, ac - 2);
		}
	}
}
