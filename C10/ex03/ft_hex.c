/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:19:41 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/12 11:19:41 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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

void	ft_put_hexa(unsigned long nb)
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

void	ft_put_content_hexa(unsigned char *str, int size)
{
	int	left;
	int	shift;
	int	i;

	write(1, "  ", 2);
	i = 0;
	while (i < size)
	{
		shift = 4;
		while (shift >= 0)
		{
			left = str[i] >> shift & 0xf;
			if (left > 9)
				left += 'a' - 10;
			else
				left += '0';
			write(1, &left, 1);
			shift -= 4;
		}
		write(1, "  ", 1 + (i == 7));
		i++;
	}
	while (i < 16)
	{
		write(1, "   ", 3);
		i++;
	}
}

void	ft_put_content(unsigned char *str, int size)
{
	int	i;
	int	is_printable;
	if (!size)
	{
		write(1, "\n", 1);
		return;
	}
	write(1," |", 2);
	i = 0;
	while (i < size)
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

