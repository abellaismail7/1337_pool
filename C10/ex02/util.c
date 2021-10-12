#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
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

int ft_read(int bufnb, void *buf, int count)
{
	int cn;
	int i;

	cn = 0;
	while(count != cn){
		i = read(bufnb, buf+cn, count - cn); 
		if(!i)
			return cn;
		cn += i;
	}
	return cn;
}

void tail_buf(int bufnb, int count)
{
	char *buf;
	int bufcn;
	int j;
	
	buf = malloc(sizeof(char) * count * 2);
	bufcn = 0;
	while(1)
	{
		j = ft_read(bufnb, buf + count, count);
		bufcn += j;
		if(!j)
			break;
		ft_strncpy(buf, buf + count, j); 
	}
	if(count > bufcn)
		write(1, buf, bufcn);
	else if(count)
		write(1, buf + (bufcn % count), count);
	free(buf);
}
