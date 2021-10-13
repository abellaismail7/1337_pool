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

void ft_foreach(int *tab, int length, void(*f)(int));

void ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;

	i = 0;
	while(i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

