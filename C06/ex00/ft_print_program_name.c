#include<unistd.h>

int main(int argc, char** argv)
{
	int i;
	char *str; 

	if(argc > 0)
	{
		str = argv[0]; 
		i = 0;
		while (str[i])
			i++;
		write(1, str, i);
	}
}
