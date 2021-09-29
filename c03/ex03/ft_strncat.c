/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:02:20 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/29 14:27:12 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

#include<stdio.h>
#include<string.h>
int main()
{
	int n = 3;
	char s1[] = "ismail";
	char s2[20] = "bella";
	char s3[20] = "bella";

	char *r1 = ft_strncat(s2,s1,n);
	char *r2 = strncat(s3,s1,n);
	
	printf("%s\n%s",r1 ,r2 );
}
