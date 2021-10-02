/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 08:28:59 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/02 18:16:10 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	validate(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
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

char	*get_sign(int *sign, char *str)
{
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		res;
	int		len;
	char	c;

	while (is_space(*str))
		str++;
	sign = -1;
	str = get_sign(&sign, str);
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
//
//#include<stdio.h>
//int main()
//{
//	int res = ft_atoi_base("\t\v\012\n   -+---+1123","0123djksf9");
//	printf("%d", res);
//}
