/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:00:38 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/01 10:13:20 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int est = 1 << 30;
	int res = 0;


	while(est > nb)
		est >>= 2;

	while(est)
	{
		if (nb >= res + est)
		{
			nb -= res + est;
			res = (res >> 1) + est;
		}
		else
			res >>= 1;
		est >>= 2;
	}
	if(nb == 0)
		return res;
	else
		return 0;
}


int ft_sqrt1(int nb)
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
	if (nb == est * est)
		return est;
	else
		return 0;
}

#include<stdio.h>
int main()
{
	printf("%d",ft_sqrt1(0));
}
