/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 08:28:59 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 15:46:39 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	get_sign(char *str)
{
	int	sign;

	sign = 1;
	while (*str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign -= 1;
		str++;
	}
	return (sign);
}

int	get_position(char *base, char c)
{
	int	i;

	if (!c)
		return (-1);
	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (base[i])
		return (i);
	else
		return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		res;
	int		len;
	char	c;

	sign = get_sign(str) * -1;
	len = validate(base);
	if (len < 2)
		return (0);
	res = 0;
	while (1)
	{
		c = get_position(base, *str);
		if (c < 0)
			break ;
		res *= len;
		res -= c;
		str++;
	}
	return (res * sign);
}

#include<stdio.h>
int main()
{
	int res = ft_atoi_base("bacd","abcde");
	printf("%d", res);
}
