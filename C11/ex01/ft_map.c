/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:17:31 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 20:17:31 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ntab;

	if (tab == 0 || length < 0)
		return (0);
	ntab = malloc(sizeof(int) * length);
	if (ntab == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		ntab[i] = (*f)(tab[i]);
		i++;
	}
	return (ntab);
}
//
//void	ft_foreach(int *tab, int length, void (*f)(int))
//{
//	int	i;
//
//	if (tab == 0)
//		return ;
//	i = 0;
//	while (i < length)
//	{
//		(*f)(tab[i]);
//		i++;
//	}
//}
//
//#include<stdio.h>
//void print(int a)
//{
//	printf("%d\n", a);
//}
//int inc(int a)
//{
//	return a * 9;
//}
//int main()
//{
//	int a[] = {1, 2, 8, 9};
//	int *arr = ft_map(a, 3,inc);
//	ft_foreach(arr, 4, print);
//		
//}
