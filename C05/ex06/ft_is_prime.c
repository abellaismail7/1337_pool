/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:13:50 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/01 12:35:02 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(int nb)
{
	int est;
	int i;

	if (nb < 1 )
		return 0;
	est = 1 << 30;
	while(est > nb)
		est >>= 1;
	
	i = (est + nb / est) >> 1;
	while(i < est)
	{
		est = i;
		i = (est + nb / est) >> 1;
	}
	return est;
}

int	ft_is_prime(int nb)
{
	int i;
	int sq;

	if(nb < 2)
		return 0;
	
	sq = ft_sqrt(nb);

	i = 2;
	while (i <= sq)
	{
		if(nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}

#include<stdio.h>
int main()
{
	for(int i = 0; i < 100; i++)
	{
		int a =ft_is_prime(i);
		if (a)
			printf("%d\n",i);
	}
}
