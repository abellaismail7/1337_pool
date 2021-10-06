/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:49 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/06 15:12:52 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	validate(char *base);

int	ft_atoi_base(char *str, char *base, int len);

int nbr_size(int nbr, int len)
{
	int i;

	i = 1;
	while (nbr)
	{
		nbr /= len;
		i++;
	}
	
	return i;
}

char	*num_to_base(int nbr, char *base, int len)
{
	int		i;
	int		is_neg;
	char	*result;

	is_neg = nbr < 0;
	i = (nbr <= 0) + nbr_size(nbr, len);
	result = malloc(sizeof(char) * i);
	result[0] = '-';
	result[--i] = 0;
	if (!is_neg)
		nbr *= -1;
	while (--i >= is_neg)
	{
		result[i] = base[(nbr % len * -1)];
		nbr /= len;
	}
	return (result);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int number;
    int from_base_len = validate(base_from);
    int to_base_len = validate(base_to);
    if (from_base_len < 2 || to_base_len < 2)
    	return (NULL);
    number = ft_atoi_base(nbr, base_from, from_base_len);
    return (num_to_base(number, base_to, to_base_len));
}

int main()
{
	char *res = ft_convert_base("2147483647","0123456789","0123456789");
    printf("%s", res);
	free(res);
}
