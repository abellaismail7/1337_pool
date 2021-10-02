/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:26:43 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/28 16:15:57 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_hexa(unsigned long nb)
{
	char	c;
	int		i;

	i = 16 * 4;
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
		if (i % 2 == 1 || i == (a - 1))
			write(1, " ", 1);
		i++;
	}
}

void	print_content(char *str, int a)
{
	int	i;
	int	is_printable;

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
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*ret;
	int		i;
	int		a;

	i = 0;
	a = 16;
	ret = addr;
	while (size)
	{
		if (size < 16)
			a = size;
		print_hexa((unsigned long) addr);
		write(1, ": ", 2);
		print_content_hexa((unsigned char *) addr, a);
		print_content((char *) addr, a);
		size -= a;
		i++;
		addr += 16;
		write(1, "\n", 1);
	}
	return (ret);
}
