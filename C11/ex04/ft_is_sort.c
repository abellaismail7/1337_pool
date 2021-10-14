/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:31:55 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 20:31:55 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// switch if f returns true
int	_ft_is_sort(int *tab, int length, int(*dir)(int), int(*f)(int , int))
{
	int	i;
	int j;

	i = 0;
	while (i < length -1)
	{
		j = i + 1;
		while (j < length)
		{
			if ((*dir)((*f)(tab[i], tab[j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_sort_asc(int res)
{
	return res < 0;
}

int	ft_is_sort_desc(int res)
{
	return res > 0;
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	return _ft_is_sort(tab, length, &ft_is_sort_asc, f) || _ft_is_sort(tab, length, &ft_is_sort_desc, f);
}

#include<stdio.h>
int is_even(int a, int b)
{
	if(a < b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}
int main()
{
	int a[] = {-2 , -1 , 0};
	printf("%d", ft_is_sort(a, 3, is_even));
}
