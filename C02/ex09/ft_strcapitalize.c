/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:33:37 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/02 09:14:08 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		is_cap;
	int		is_num;
	int		is_low;
	int		is_upp;
	char	*ret;

	ret = str;
	is_cap = 1;
	while (*str)
	{
		is_num = *str >= '0' && *str <= '9';
		is_low = *str >= 'a' && *str <= 'z';
		is_upp = *str >= 'A' && *str <= 'Z';
		if (is_cap && is_low)
			(*str) -= 32;
		else if (!is_cap && is_upp)
			(*str) += 32;
		is_cap = !(is_num || is_low || is_upp);
		str++;
	}
	return (ret);
}
//
//#include<stdio.h>
//int main()
//{
//	char a[] = "salut, comment tu vas ? 42MoTs quarante-deux; cinquante+et+un";
//	char *str = ft_strcapitalize(a);
//	printf("%s\n%s",a,str);
//
//}
