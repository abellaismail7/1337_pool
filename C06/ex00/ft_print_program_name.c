/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:56:23 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/04 10:56:27 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc > 0)
	{
		str = argv[0];
		i = 0;
		while (str[i])
			i++;
		write(1, str, i);
		write(1, "\n", 1);
	}
}
