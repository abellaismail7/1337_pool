/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:02:20 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/29 14:59:11 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(unsigned int a, unsigned int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = size;
	if (size == 0)
		return (0);
	while (dest[i])
		i++;
	k -= i + 1;
	while (src[j])
	{
		if (j < k)
			dest[i++] = src[j];
		j++;
	}
	dest[i] = 0;
	if (i < size)
		return (j + i);
	else
		return (j + size);
}

#include<stdio.h>
#include<string.h>
int main()
{
	int n = 3;
	char s1[] = "ismail";
	char s2[20] = "bella";
	char s3[20] = "bella";

	int a = ft_strlcat(s2,s1,n);
	int b = strlcat(s3,s1,n);
	
	printf("%s  %d\n%s  %d",s2 ,a ,s3 ,b );
}
