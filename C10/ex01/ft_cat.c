/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:47:55 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 12:47:55 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include "util.h"

void	read_from_stdin(void)
{
	char	c;

	while (read(FT_STDIN, &c, 1))
		write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	if (ac == 1)
		read_from_stdin();
	else if (ac > 1)
	{
		i = 1;
		while (av[i])
		{
			if (*av[i] == '-' && !av[i][1])
				read_from_stdin();
			else
				j |= print_file(av[i], basename(av[0]));
			i++;
		}
	}
	return (j);
}
