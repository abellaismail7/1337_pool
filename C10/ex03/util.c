#include <errno.h>
#include<stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "util.h"
#include "ft_str.h"
#include "ft_hex.h"

void dump_buf(int bufnb)
{
	unsigned char bytes[16];
	int i;
	int j;
	int add;
	int rest;

	add = 0;
	j = 16;
	while(1)
	{
		rest = add % 16;
		i = read(bufnb, bytes + rest, 16 - rest);
		
		if(rest + i == 16)
		{
			ft_put_hexa((add/16) * 16);
			ft_put_content_hexa(bytes, 16);
			ft_put_content(bytes, 16);
		}
		else if(!i)
		{
			ft_put_hexa((add/16) * 16);
			ft_put_content_hexa(bytes, rest);
			ft_put_content(bytes, rest);
			ft_put_hexa(add);
			break;
		}
		add += i;
	}
	write(1, "\n", 1);
}

int dump_file(char *filename)
{
	int fp;
	char *str;
	
	errno = 0;
	fp = open(filename, O_RDWR);
	if (errno)
	{
		str = strerror(errno);
		write(1, "ft_tail", 6);
		write(1, str, ft_strlen(str));
		errno = 0;
		return -1;
	}
	if (fp < 0)
		return 0;
	dump_buf(fp);

	close(fp);
	return 1;
}
