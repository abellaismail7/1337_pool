#include<stdio.h>
#include<stdlib.h>

int	has_char(char *str, char c)
{
	while(*str)
	{
		if (*str == c)
			return 1;
		str++;
	}
	return 0;
}


int split_counter(char *str, char *charset)
{
    int i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		while(str[i] && !has_char(charset, str[i])){
			i++;
		}
		while(has_char(charset, str[i]))
			i++;
		count++;
	}

    return count;
}

int word_counter(char *str, char *charset)
{
	int count;

	count = 0;
	while(*str && !has_char(charset,*str))
	{
		
		count++;
		str++;
	}
	
	return count;
}
char **ft_split(char *str, char *charset)
{
	char **result;
	int spcount;
	int wcount;
	int i;
	int j;

	while(has_char(charset, *str))
		str++;
	spcount = split_counter(str, charset);
	result = malloc(sizeof(char*) * (spcount + 1));
	if(result)
		return (0);

	result[spcount] = 0;
	i = 0;
	while(i < spcount)
	{
		wcount = word_counter(str, charset); 
		result[i] = malloc(sizeof(char) * (wcount + 1));
		result[i][wcount] = 0;
		j = 0;

		while(j < wcount)
		{
			result[i][j] = str[j];	
			j++;
		}
		str += j;
		while(has_char(charset, *str))
			str++;
		i++;
	}
	
    return result;
}

int main()
{
    //int i = split_counter("kjd ,jkds, djsjkdl" , "d");
	//return i;
	int i = 0;
    char **strs = ft_split("          " , "   ");
	if(!strs)
		return 1;
	while(strs[i])
	{
		printf("--%s--\n", strs[i]);
		free(strs[i]);
		i++;
	}
	free(strs);
}
