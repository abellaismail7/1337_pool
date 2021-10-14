/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:27:35 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 20:27:35 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}
//
//#include<stdio.h>
//int is_even(char *a)
//{
//	return a[0] == 'z';
//}
//int main()
//{
//	char *a[] = {"ssda", "sada", "ssd", "ssdsf"};
//	printf("%d", ft_count_if(a, 4, is_even));
//		
//}
