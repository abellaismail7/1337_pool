/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:28:58 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/24 09:41:53 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	fillnext(char *arr)
{
	int	last;

	last = *arr;
	while (*arr)
	{
		*arr = last + 1;
		last++;
		arr++;
	}
}

int	nextcomb(char *arr, int n)
{
	int	l;
	int	i;
	int	max;

	l = n;
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
	i = 10 - n + '0';
	if (*arr == i)
		return (0);
	return (1);
}

void	fillarr(char *arr, int n)
{
	int	r;

	r = 0;
	while (r < n)
	{
		arr [r] = r + '0';
		r++;
	}
	arr[r - 1]--;
	arr[n] = 0;
}

void	ft_print_combn(int n)
{
	char	arr[11];

	fillarr(arr, n);
	while (nextcomb(arr, n))
	{
		write(1, arr, n);
		write(1, ", ", 2);
	}
	write(1, arr, n);
}
