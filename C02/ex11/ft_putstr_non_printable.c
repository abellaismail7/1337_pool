/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:56:14 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/28 15:57:46 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_hexa(unsigned int nb)
{
	char	c;
	int		i;

	i = 8;
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

void	ft_putstr_non_printable(char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		if (c < 32 || c > 126)
		{
			write(1, "\\", 1);
			print_hexa(*str);
		}
		else
			write(1, &c, 1);
		str++;
	}
}
//
//int main()
//{
//	ft_putstr_non_printable("Coucou\nt\xecu \xfevas bien ?");
//}
