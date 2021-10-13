/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:55:46 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 10:55:46 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "util.h"
#include "ft_str.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (ac > 1)
	{
		if (ft_strcmp("-C", av[1]) == 0)
		{
			if (ac == 2)
				dump_buf();
			else
				j |= dump_files(av + 2, ac - 2);
		}
	}
	write(1, "\n", 1);
	return (j);
}
