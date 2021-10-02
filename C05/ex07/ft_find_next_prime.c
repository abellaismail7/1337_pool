/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 09:30:38 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/02 09:40:42 by iait-bel         ###   ########.fr       */
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

int ft_find_next_prime(int nb)
{

	while(!ft_is_prime(nb))
		nb++;
	return nb;	
}

#include<stdio.h>
int main()
{
	int a =ft_find_next_prime(0);
	printf("%d\n",a);
}
