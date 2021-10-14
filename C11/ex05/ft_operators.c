/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opertors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:49:36 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 20:49:36 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "ft_calc.h"

void	ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

int	check_zero(char operator, int val)
{
	if (val != 0)
		return (1);
	if (operator == '%')
	{
		ft_puterr("Stop : modulo by zero\n");
		return (0);
	}
	if (operator == '/')
	{
		ft_puterr("Stop : division by zero\n");
		return (0);
	}
	return (1);
}

int	calc(char operator, int a, int b)
{
	if (operator == '+')
		return (add(a, b));
	else if (operator == '-')
		return (subtract(a, b));
	else if (operator == '*')
		return (multi(a, b));
	else if (operator == '/')
		return (div(a, b));
	else if (operator == '%')
		return (mod(a, b));
	return (0);
}
