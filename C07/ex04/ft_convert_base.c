
#include<stdio.h>
#include<stdlib.h>
int	validate(char *base)
{
	int	i;
	int	j;
    int is_space;

	i = 0;
	while (base[i])
	{
        is_space = (base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ';
		if (base[i] == '+' || base[i] == '-' || is_space)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	get_position(char *base, char c)
{
	int	i;

	if (!c)
		return (-1);
	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (base[i])
		return (i);
	else
		return (-1);
}

char	*get_sign(int *sign, char *str)
{
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base, int len)
{
	int		sign;
	int		res;
	char	c;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = -1;
	str = get_sign(&sign, str);
	res = 0;
	while (1)
	{
		c = get_position(base, *str);
		if (c < 0)
			break ;
		res *= len;
		res -= c;
		str++;
	}
	return (res * sign);
}

char *num_to_base(int nbr, char *base)
{
    int		i;
	int		j;
    int		len;
    int		is_neg;
	char	*result;

    len = 0;
    i = 1;
	is_neg = nbr < 0;
    while(base[len])
        len++;

	j = nbr;
    while(j)
	{
		j /= len;
		i++;
	}
	i += is_neg;
	result = malloc(sizeof(char) * i);
	result[0] = '-';
	result[--i] = 0;
	
	if(!is_neg)
		nbr *= -1;
	while(--i >= is_neg)
	{
		result[i] = base[(nbr % len  * -1)] ;
		nbr /= len;
	}
    return result;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int number;
    int from_base_len = validate(base_from);
    int to_base_len = validate(base_to);
	if (from_base_len < 2 || to_base_len < 2)
		return (NULL);
    number = ft_atoi_base(nbr, base_from, from_base_len);
    return num_to_base(number, base_to);
}

int main()
{
	char *res = ft_convert_base("1","0123456789","01");
    printf("%s", res);
	free(res);
}
