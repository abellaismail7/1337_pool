/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:23:25 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/29 18:23:49 by iait-bel         ###   ########.fr       */
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
