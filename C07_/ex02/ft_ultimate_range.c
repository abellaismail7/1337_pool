/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:31 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/07 07:45:51 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i++] = min++;
	}
	return (size);
}
//#include<stdio.h>
//int main()
//{
//	int *range;
//	int s = ft_ultimate_range(&range,-15, 6);
//	if (!range)
//		return 9;
//	while (s--)
//	{
//		printf("%d, ", range[s]);
//	}
//
//	free(range);
//}
