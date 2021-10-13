/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:21:49 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/12 18:21:49 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "util.h"
#include "ft_str.h"

int	g_is_first = 1;

int	show_errno(char *filename, char *basename)
{
	char	*str;

	str = strerror(errno);
	write(2, basename, ft_strlen(basename));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}

int	tail_file(char *filename, int count, int is_multi, char *basename)
{
	int		fp;
	char	*str;

	errno = 0;
	fp = open(filename, O_RDWR);
	if (errno && errno != EISDIR)
		return (show_errno(filename, basename));
	if (is_multi)
	{
		str = "\n==> ";
		write(1, str + g_is_first, 4 + !g_is_first);
		write(1, filename, ft_strlen(filename));
		write(1, " <==\n", 5);
	}
	g_is_first = 0;
	if (!errno)
	{
		tail_buf(fp, count);
		close(fp);
	}
	return (fp < 0 && errno != EISDIR);
}

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

void	tail_buf(int bufnb, int count)
{
	char	*buf;
	int		bufcn;
	int		j;

	buf = malloc(sizeof(char) * count * 2);
	bufcn = 0;
	while (1)
	{
		j = ft_read(bufnb, buf + count, count);
		bufcn += j;
		if (!j)
			break ;
		ft_strncpy(buf, buf + count, j);
	}
	if (count > bufcn)
		write (1, buf, bufcn);
	else if (count)
		write(1, buf + (bufcn % count), count);
	free(buf);
}
