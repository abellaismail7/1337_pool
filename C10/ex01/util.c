/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:50:15 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 12:50:15 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_file(char *filename, char *basename)
{
	int		fp;
	char	c;
	char	*str;

	fp = open(filename, O_RDWR);
	if (errno)
	{
		str = strerror(errno);
		write(2, basename, ft_strlen(basename));
		write(2, ": ", 2);
		write(2, filename, ft_strlen(filename));
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		errno = 0;
		return (1);
	}
	if (fp < 0)
		return (1);
	while (read(fp, &c, 1))
		write(1, &c, 1);
	close(fp);
	return (0);
}
