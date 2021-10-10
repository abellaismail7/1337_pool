/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:41 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/06 15:12:42 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	count_join(int size, char **strs, char *sep)
{
	int		count;
	int		sep_count;
	int		i;
	int		j;

	count = 0;
	sep_count = 0;
	i = 0;
	while (sep[sep_count])
		sep_count++;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		if (i != size - 1)
			count += sep_count;
		i++;
	}
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		count;
	int		i;
	int		j;
	char	*result;

	i = 0;
	count = count_join(size, strs, sep) + 1;
	result = malloc(sizeof(char) * count);
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[count++] = strs[i][j++];
		if (i != size - 1)
		{
			j = 0;
			while (sep[j])
				result[count++] = sep[j++];
		}
		i++;
	}
	result[count] = 0;
	return (result);
}
//#include<stdio.h>
//int main()
//{
//    char *s = "sdk\0bjhk\0cdfjls";
//
//    char *strs[3] = {s,s+4,s+ 9};
//
//    char *str = ft_strjoin(0,strs,"");
//    
//    printf("%s", str);
//
//    free(str);
//}
