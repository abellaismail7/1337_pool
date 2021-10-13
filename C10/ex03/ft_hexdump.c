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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include "util.h"
#include "ft_str.h"
#include "ft_options.h"

int	main(int ac, char **av)
{
	int				i;
	int				j;
	int				expanded;
	t_ft_options	op;

	i = 2;
	j = 0;
	expanded = (av[1] && ft_strcmp("-C", av[1]) == 0);
	op.basename = basename(av[0]);
	op.cols = 2 + expanded;
	if (ac == 1 + expanded)
	{
		dump_buf(op.cols);
		return (0);
	}
	op.size = ac - 1 - expanded;
	op.files = av + 1 + expanded;
	dump_files(op);
	return (j);
}
