#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"

int g_is_first = 1;

int ft_strlen(char *str)
{
	int i;

	i= 0;
	while(str[i])
		i++;
	return i;
}

int tail_file(char *filename, int count, int is_multi)
{
	int fp;
	char *str;

	errno = 0;
	fp = open(filename, O_RDWR);
	if (errno && errno != EISDIR)
	{
		str = strerror(errno);
		write(2, "ft_tail: ", 9);
		write(2, filename, ft_strlen(filename));
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		return -1;
	}
	if(is_multi)
	{
		str = "\n==> ";
		write(1, str + g_is_first, 4 + !g_is_first);
		write(1, filename, ft_strlen(filename));
		write(1, " <==\n", 5);
	}
	g_is_first = 0;
	if(!errno)
	{
		tail_buf(fp, count);
		close(fp);
	}
	return fp < 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int ft_atoi(char *str)
{
	int res;

	res = 0;
	while(*str)
	{
		if(*str < '0' || *str > '9')
		{
			return FT_ERR_ILLEGAL_OFFSET;
		}
		res *= 10;
		res += *str - '0';
		str++;
	}
	return res;
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = 0;
	return (dest);
}

void tail_stdin(int count)
{
	char *buf;
	int i;
	int j;
	int size;
	
	size = count * 2;
	buf = malloc(sizeof(char) * size);

	i = 0;
	while(1)
	{
		j = read(FT_STDIN, buf + count, count);
		i += j;
		ft_strncpy(buf,buf + count,count); 
		if(!j)
			break;
	}
	if(!count)
		return;
	write(1, buf + (i % count), count);
	free(buf);

}


void tail_buf(int bufnb, int count)
{
	char *buf;
	int i;
	int j;
	int size;
	
	if(!count)
		return;
	size = count * 2;
	buf = malloc(sizeof(char) * size);

	i = 0;
	while(1)
	{
		j = read(bufnb, buf + count, count);
		i += j;
		ft_strncpy(buf,buf + count,count); 
		if(!j)
			break;
	}

	write(1, buf + (i % count), count);
	free(buf);
}
