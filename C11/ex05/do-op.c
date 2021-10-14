/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:37:44 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 20:37:44 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_nbr.h"
#include "ft_operators.h"

int	main(int ac, char **av)
{
	int		val1;
	int		val2;
	char	operator;
	int		res;

	res = 0;
	if (ac == 4)
	{
		val1 = ft_atoi(av[1]);
		operator = av[2][0];
		val2 = ft_atoi(av[3]);
		if (check_zero(operator, val2) == 0)
			return (1);
		if (av[2][1] == 0)
			res = calc(operator, val1, val2);
		ft_putnbr(res);
	}
}
