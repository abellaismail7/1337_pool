/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:32:00 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 18:38:30 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return 0;
	if (nb < 2)
		return 1;
	
	return nb * ft_recursive_factorial(nb - 1);
	
}

#include<stdio.h>
int main()
{
	
	printf("%d", ft_recursive_factorial(7));
}
