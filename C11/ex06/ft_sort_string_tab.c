/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:06:01 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/13 21:06:01 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_sort_string_tab(char **tab)
{
	int 	i;
	char *tmp;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if(ft_strncmp(tab[i], tab[j]) > 0)
			{
				tmp =  tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}


