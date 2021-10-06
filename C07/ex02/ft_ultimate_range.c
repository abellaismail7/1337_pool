/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:31 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/06 15:12:32 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_range_ultimate(int **range, int min, int max)
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
//	int s = ft_range_ultimate(&range,-15, -36);
//	if (!range)
//		return 9;
//	while (s--)
//	{
//		printf("%d, ", range[s]);
//	}
//
//	free(range);
//}
