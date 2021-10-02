/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:18:45 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 10:34:51 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}
//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s1[] = "===";
//	char s2[20] = "jkdshs";
//	char s3[20] = "jkdshs";
//
//	ft_strcat(s2,s1);
//	strcat(s3,s1);
//	
//	printf("%s %s",s2 ,s3 );
//}
