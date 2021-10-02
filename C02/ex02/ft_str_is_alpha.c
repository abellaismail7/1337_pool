/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:47:01 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/28 13:46:32 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	char	c;
	int		is_low;
	int		is_upp;

	while (*str)
	{
		c = *str;
		is_low = c >= 'a' && c <= 'z';
		is_upp = c >= 'A' && c <= 'Z';
		if (!is_low && !is_upp)
			return (0);
		str++;
	}
	return (1);
}
