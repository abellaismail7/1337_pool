/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:40:50 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 18:48:55 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int res;

	res = 1;
	if (nb == 0)
	{
		if (power < 0)
			return 0;
		return (1);
	}
	while (power)
	{
		res *= nb;	
		power--;
	}
	return (res);
	
}

#include<stdio.h>
int main()
{
	
	printf("%d", ft_iterative_power(4,2));
}
