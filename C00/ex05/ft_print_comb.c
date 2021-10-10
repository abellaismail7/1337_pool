/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:56:20 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/24 10:37:33 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	fillnext(char *arr)
{
	int	last;

	last = *arr;
	while (*arr)
	{
		*arr = ++last;
		arr++;
	}
}

int	nextcomb(char *arr)
{
	int	l;
	int	max;

	l = 3;
	max = '9';
	while (l--)
	{
		if (arr[l] == max)
			max--;
		else
		{
			fillnext(arr + l);
			break ;
		}
	}
	if (*arr == '7')
		return (0);
	return (1);
}

void	ft_print_comb(void)
{
	char	arr [4];

	arr [0] = '0';
	arr [1] = '1';
	arr [2] = '1';
	arr [3] = 0;
	while (nextcomb(arr))
	{
		write(1, arr, 3);
		write(1, ", ", 2);
	}
	write(1, arr, 3);
}
