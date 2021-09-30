/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:28:07 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 18:31:15 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int res;

	res = 1;
	if (nb <= 0)
		return (0);
	while (nb)
	{
		res *= nb;	
		nb--;
	}
	return (res);
	
}

#include<stdio.h>
int main()
{
	
	printf("%d", ft_iterative_factorial(7));
}
