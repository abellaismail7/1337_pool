/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:42:49 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 09:42:49 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	dump_file(int *add, int fp);
void	put_dump_line(int add, unsigned char *bytes, int index);
unsigned char	g_bytes[16];
unsigned char	g_prev_bytes[16];
int				g_is_same = 0;

void	dump_buf()
{
	int	add;
	int rest;

	add = 0;
	rest = dump_file(&add, FT_STDIN);
	put_dump_line(add, g_bytes, rest);
	ft_put_hexa(add);
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

void	put_dump_line(int add, unsigned char *bytes, int index)
{
	if (ft_strncmp(bytes, g_prev_bytes, 16) == 0)
	{
		if (!g_is_same)
			write(1, "*\n", 2);
		g_is_same = 1;
	}
	else
	{
		g_is_same = 0;
		ft_put_hexa(add / 16 * 16);
		ft_put_content_hexa(bytes, index);
		ft_put_content(bytes, index);
	}
	ft_strncpy(g_prev_bytes, bytes, 16);
}

int	dump_file(int *add, int fp)
{
	int	cn;
	int	rest;

	while (fp > -1)
	{
		rest = *add % 16;
		g_bytes[rest] += 1;
		cn = ft_read(fp, g_bytes + rest, 16 - rest);
		if (cn == 0)
		{
			close(fp);
			break ;
		}
		if (rest + cn == 16)
			put_dump_line(*add, g_bytes, rest + cn);
		*add += cn;
	}
	return (rest);
}

int	dump_files(char **files, int size)
{
	int				i;
	int				rest;
	int				add;
	int				fp;
	int				res;

	i = 0;
	add = 0;
	res = 0;
	while (i < size)
	{
		fp = open_file(files[i]);
		res |= fp < 0;
		rest = dump_file(&add, fp);
		i++;
	}
	if (add != 0)
	{
		if(rest > 0)
			put_dump_line(add, g_bytes, rest);
		ft_put_hexa(add);
		write(1, "\n", 1);
	}
	return (res);
}
