/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:07:02 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/02 20:12:39 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main(int argc, char** argv)
{
	int i;
	int j;
	char *str; 

	i = argc;
	while (--i)
	{
		str = argv[i]; 
		j = 0;
		while (str[j])
			j++;
		write(1, str, j);
		write(1, "\n", 1);
	}
}
