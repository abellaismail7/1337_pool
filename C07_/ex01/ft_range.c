/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:22 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/06 15:12:25 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	size = max - min;
	if (max <= min)
		return (0);
	range = malloc(sizeof(int) * size);
	i = 0;
	while (min < max)
	{
		range[i++] = min++;
	}
	return (range);
}
//#include<stdio.h>
// testi alklb
//int main()
//{
//	int *range = ft_range(7, 80);
//	if (!range)
//		return 9;
//	for(int i = 0; i < 79; i++)
//	{
//		printf("%d %d\n", i, range[i]);
//	}
//
//	free(range);
//}
