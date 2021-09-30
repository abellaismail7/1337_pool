/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:36:39 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 07:12:11 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(char * str){
	int sign = -1;
	int res;
	if(*str == '-')
	{
		str++;
		sign = 1;
	}
	else if(*str == '+')
		str++;

	res = 0;
	while (*str >= '0' && *str <= '9'){
		res *= 10;
		res -= *str - '0';
		str++;
	}

    return res * sign ;
}

#include<stdio.h>
int main()
{
	int res = ft_atoi("2147483646");
	printf("%d", res);
}
