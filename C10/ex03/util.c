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

//#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "util.h"
#include "ft_str.h"
#include "ft_hex.h"
#include "ft_error.h"

void			dump_file(int *add, int fp, int cols);
void			put_dump_line(int add, unsigned char *bytes,
					int index, int cols);
unsigned char	g_bytes[16];
unsigned char	g_prev_bytes[16];
int				g_is_same = 0;

void	dump_buf(int cols)
{
	int	add;

	add = 0;
	dump_file(&add, FT_STDIN, cols);
	if (add != 0)
	{
		if (add % 16 > 0)
			put_dump_line(add, g_bytes, add % 16, cols);
		ft_put_hexa(add, cols);
		write(1, "\n", 1);
	}
}

int	open_file(char *filename, char *basename)
{
	int		fp;

	errno = 0;
	fp = open(filename, O_RDWR);
	show_errno(basename, filename);
	return (fp);
}

void	put_dump_line(int add, unsigned char *bytes, int index, int cols)
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
		ft_put_hexa(add / 16 * 16, cols);
		if (cols == 3)
			write(1, " ", 1);
		ft_put_content_hexa(bytes, index, cols);
		if (cols == 3)
			ft_put_content(bytes, index);
		write(1, "\n", 1);
	}
	ft_strncpy(g_prev_bytes, bytes, 16);
}

void	dump_file(int *add, int fp, int cols)
{
	int	cn;
	int	rest;

	rest = 0;
	while (fp > -1)
	{
		rest = *add % 16;
		g_bytes[rest] += 1;
		cn = ft_read(fp, g_bytes + rest, 16 - rest);
		if (cn == 0)
			break ;
		if (rest + cn == 16)
			put_dump_line(*add, g_bytes, rest + cn, cols);
		*add += cn;
	}
	close(fp);
}

int	dump_files(t_ft_options op)
{
	int	i;
	int	add;
	int	fp;
	int	res;

	i = 0;
	add = 0;
	res = 0;
	while (i < op.size)
	{
		fp = open_file(op.files[i], op.basename);
		res |= fp < 0;
		dump_file(&add, fp, op.cols);
		i++;
	}
	show_errno(op.files[op.size -1], op.basename);
	if (add != 0)
	{
		if (add % 16 != 0)
			put_dump_line(add, g_bytes, add % 16, op.cols);
		ft_put_hexa(add, op.cols);
		write(1, "\n", 1);
	}
	return (res);
}
