#include <unistd.h>
#include <fcntl.h>

int print_file(char *filename)
{
	int fp;
	char c;

	fp = open(filename, O_RDONLY); // read mode
	if (fp < 0)
		return 0;
	while (read(fp, &c, 1))
		write(1, &c, 1);
	close(fp);
	return 1;
}

int main(int ac, char **av)
{
	
	if(ac == 1)
		write(1, "File name missing.", 18);
	else if(ac == 2)
	{
		if (!print_file(av[1]))
			write(1, "Cannot read file.", 17);
	}
	else
		write(1, "Too many arguments.", 19);
}
