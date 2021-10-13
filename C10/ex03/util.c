#include<stdio.h>
#include <errno.h>
#include<stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "util.h"
#include "ft_str.h"
#include "ft_hex.h"

int	ft_read(int bufnb, void *buf, int count)
{
	int	cn;
	int	i;

	cn = 0;
	while (!count || count != cn)
	{
		i = read(bufnb, buf + cn, count - cn + (count == 0));
		if (!i)
			return (cn);
		cn += i;
	}
	return (cn);
}

void	dump_buf(int bufnb)
{
	unsigned char	bytes[16];
	int				i;
	int				j;
	int				add;
	int				rest;

	add = 0;
	j = 16;
	while (1)
	{
		rest = add % 16;
		i = read(bufnb, bytes + rest, 16 - rest);
		
		if (rest + i == 16)
		{
			ft_put_hexa((add/16) * 16);
			ft_put_content_hexa(bytes, 16);
			ft_put_content(bytes, 16);
		}
		else if (!i)
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

int	open_file(char *filename)
{
	int		fp;
	char	*str;
	
	errno = 0;
	fp = open(filename, O_RDWR);
	if (errno)
	{
		str = strerror(errno);
		write(2, "ft_hexdump :", 12);
		write(2, filename, ft_strlen(filename));
		write(2, " :", 2);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		errno = 0;
		return (-1);
	}
	if (fp < 0)
		return (-1);
	return (fp);
}

void	dump_files(char **files, int size)
{
	int i;
	int rest;
	int cn;
	int add;
	int fp;
	unsigned char bytes[16];

	cn = 0;
	rest = 0;
	i = 0;
	add = 0;
	while (i < size){
		fp = open_file(files[i]);
		while (fp > -1)
		{
			rest = add % 16;
			cn = read(fp, bytes + rest, 16 - rest);	

			if(cn == 0)
			{
				close(fp);
				break;
			}

			if (rest + cn  == 16){
				ft_put_hexa(add);
				ft_put_content_hexa(bytes, rest + cn);
				ft_put_content(bytes, rest + cn);
			}
			add += cn;
		}
		i++;
	}
	ft_put_hexa(add + cn);
}

