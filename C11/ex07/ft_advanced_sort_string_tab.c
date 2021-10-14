/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:18:19 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/14 09:18:19 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*tmp;
	int		is_sorted;

	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		i = 0;
		while (tab[i] && tab[i + 1])
		{	
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				is_sorted = 0;
			}
			i++;
		}	
	}
}
