/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:23:36 by iait-bel          #+#    #+#             */
/*   Updated: 2021/09/30 18:16:25 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = size - 1;
	while (dest[i])
		i++;
	k -= i;
	while (src[j])
	{
		if (j < k)
			dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	if (i < (int) size)
		return (j + i);
	else
		return (j + size);
}
#include<stdio.h>
#include<string.h>
int main()
{
	int n = 57;
	char s1[] = "DwtVHDBFVtBFlcmkpbYjlxZoarMeEjcBVMLHYPqliwCjjfFyXZjPnsTWY";
	char s2[200] = "cBVMLHYPqliwCjjfFyXZjPnsTWY";
	char s3[200] = "cBVMLHYPqliwCjjfFyXZjPnsTWY";

	int a = ft_strlcat(s2,s1,n);
	int b = strlcat(s3,s1,n);
	
	printf("%s  %d\n",s2 ,a );
	printf("%s  %d",s3 ,b );
}
