/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:59:34 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/11 17:59:34 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include "util.h"
#include "ft_const.h"

int	get_count(int ac, char **av)
{
	if (ac < 3)
		return (FT_ERR_NO_ARG);
	if (!ft_strcmp("-c", av[1]))
	{
		return (ft_atoi(av[2]));
	}
	return (0);
}

void	show_help(int out, char *basename)
{
	write(out, "usage: ", 7);
	write(out, basename, ft_strlen(basename));
	write(out, " [-c #] [file ...]\n", 19);
}

int	show_error(char *msg, char *arg, char *basename, int help)
{
	write(2, basename, ft_strlen(basename));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	if (help)
		show_help(2, basename);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	count;
	int	j;

	count = 0;
	j = 0;
	if (ac > 1)
	{
		count = get_count(ac, av);
		if (count == FT_ERR_ILLEGAL_OFFSET)
			return (show_error("illegal offset -- ",
					av[2], basename(av[0]), 0));
		else if (count == FT_ERR_NO_ARG)
			return (show_error("option requires an argument -- ",
					"c", basename(av[0]), 1));
		else if (ac == 3)
			tail_buf(FT_STDIN, count);
		else
		{
			i = 3;
			while (av[i])
				j |= tail_file(av[i++], count, ac > 4, basename(av[0]));
		}
	}
	return (j);
}
