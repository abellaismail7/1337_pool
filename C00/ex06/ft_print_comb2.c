/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:39:34 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/23 18:51:32 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	print_num(int n)
{
	int	tmp;

	tmp = n / 10 + '0';
	write(1, &tmp, 1);
	tmp = n % 10 + '0';
	write(1, &tmp, 1);
}

void	ft_print_comb2(void)
{
	int	right;
	int	left;

	left = 0;
	while (left < 99)
	{
		right = left + 1;
		while (right < 100)
		{
			print_num(left);
			write(1, " ", 1);
			print_num(right);
			if (left != 98)
				write(1, ", ", 2);
			right++;
		}
		left++;
	}
}
