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
	int	est;
	int	nest;

	if (nb < 1 )
		return (0);
	est = 1 << 30;
	while (est > nb)
		est >>= 1;
	nest = (est + nb / est) >> 1;
	while (nest < est)
	{
		est = nest;
		nest = (est + nb / est) >> 1;
	}
	if (nb == est * est)
		return (est);
	else
		return (0);
}
//
//#include<stdio.h>
//int main()
//{
//	printf("%d",ft_sqrt(1));
//}
