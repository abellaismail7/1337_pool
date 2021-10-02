/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:57:04 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 08:49:17 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = 0;
	return (dest);
}
//
//#include<stdio.h>
//int main()
//{
//	char dest[20];
//	char src[] = "ismail";
//	ft_strncpy(dest,src,6);
//	printf("%s", src);
//}
//
