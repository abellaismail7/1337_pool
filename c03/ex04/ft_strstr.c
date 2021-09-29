/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:47 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/29 14:36:42 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int				i;
	unsigned int	j;

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

#include<stdio.h>
#include<string.h>
int main()
{
	int n = 3;
	char s1[] = "backspackjkdjks";
	char s2[] = "";
	char s3[] = "";

	char *r1 = ft_strstr(s1,s2);
	char *r2 = strstr(s1,s3);
	
	printf("%s %s",r1 ,r2 );
}
