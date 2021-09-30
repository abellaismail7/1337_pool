/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:30:54 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 14:31:03 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	int	j;

	if (n == 0)
		return (0);
	i = 0;
	j = n - 1;
	while (s1[i] && s1[i] == s2[i] && i < j)
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s1[] = "9iwp";
//	char s2[20] = "9iw";
//
//	int a = ft_strncmp(s1,s2,4);
//	int b = strncmp(s1,s2,4);
//	
//	printf("%d %d",a ,b );
//}
//
//
