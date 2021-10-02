/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:47 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 14:33:40 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!*to_find)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return (str + i);
		i++;
	}
	return (0);
}
//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char *haystack = "";
//    char *needle = "";
//
//	char *r1 = ft_strstr(haystack,needle);
//	char *r2 = strstr(haystack,needle);
//	
//	printf("%s\n%s",r1 ,r2 );
//}
