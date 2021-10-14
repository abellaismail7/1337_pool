/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 08:38:58 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/14 08:38:58 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	_ft_putnbr(int nb)
{
	int	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		_ft_putnbr(nb / 10);
		_ft_putnbr(nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	int	min;

	if (nb < 0)
	{
		write(1, "-", 1);
		min = 1 << (sizeof(int) * 8 - 1);
		if (min == nb)
		{
			_ft_putnbr(nb / 10 * -1);
			_ft_putnbr(nb % 10 * -1);
			return ;
		}
		nb = nb * -1;
	}
	_ft_putnbr(nb);
}

int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = -1;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res -= *str - '0';
		str++;
	}
	return (res * sign);
}

