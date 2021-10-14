/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:14:43 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 20:14:43 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	if (tab == 0)
		return ;
	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}
//
//#include<stdio.h>
//void print(int a)
//{
//	printf("%d\n", a * 2);
//}
//int main()
//{
//	int a[] = {-303992, 405422, 59222, -149444, 109342};
//	ft_foreach(a , 3, print);
//		
//}
