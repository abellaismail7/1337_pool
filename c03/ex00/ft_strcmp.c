/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:28:49 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 10:21:55 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s1[] = "ismail\xc9";
//	char s2[20] = "isMail";
//
//	int a = ft_strcmp(s1,s2);
//	int b = strcmp(s1,s2);
//	
//	printf("%d %d",a ,b );
//}
//
//
