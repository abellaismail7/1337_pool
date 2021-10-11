#include <errno.h>
#include<stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <util.h>

int ft_strlen(char *str)
{
	int i;

	i= 0;
	while(str[i])
		i++;
	return i;
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
void	print_hexa(unsigned long nb)
{
	char	c;
	int		i;

	i = 16 * 2;
	while (i)
	{
		i -= 4;
		c = nb >> i;
		c = c & 0xf;
		if (c > 9)
			c += 'a' - 10;
		else
			c += '0';
		write(1, &c, 1);
	}
}

void	print_content_hexa(unsigned char *arr, int a)
{
	int	left;
	int	shift;
	int	i;

	write(1, "  ", 2);
	i = 0;
	while (i < a)
	{
		shift = 4;
		while (shift >= 0)
		{
			left = arr[i] >> shift & 0xf;
			if (left > 9)
				left += 'a' - 10;
			else
				left += '0';
			write(1, &left, 1);
			shift -= 4;
		}
		if (i == 7)
			write(1, " ", 1);
		write(1, " ", 1);
		i++;
	}
}

void	print_content(unsigned char *str, int a)
{
	int	i;
	int	is_printable;

	write(1,"|", 1);
	i = 0;
	while (i < a)
	{
		is_printable = str[i] > 31 && str[i] < 127;
		if (is_printable)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1,"|", 1);
	write(1,"\n", 1);
}

void dump_buf(int bufnb)
{
	unsigned char bytes[16];
	int i;
	int add;

	add = 0;
	while(1)
	{
		i = read(bufnb, bytes, 16);
		print_hexa(add);
		print_content_hexa(bytes, i);
		print_content(bytes, i);
		if(!i)
			break;
		add += i;
	}
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
