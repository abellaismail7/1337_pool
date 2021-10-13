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

int *ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int * ntab;

	ntab = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		ntab[i] = (*f)(tab[i]);
		i++;
	}
	return (ntab);
}

