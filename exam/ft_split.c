#include<stdlib.h>
#include<stdio.h>

int is_space(char c)
{
    return c == ' ';
}

int sp_counter(char *str)
{
    int count = 0;
    while (*str){
        while (*str && !is_space(*str))
            str++;
        while(*str && is_space(*str))
            str++;
        count++;
    }
    return count;
}

char    **ft_split(char *str)
{
    while(is_space(*str))
        str++;
   int sp_count = sp_counter(str);;
   int i;
   
    int wc;
   char ** result = malloc(sizeof(char*) * (sp_count + 1)); 
   result[sp_count] = 0;
   if(!result)
       return NULL;
   i = 0;
   while(i < sp_count){
        
        printf("%d - %d\n", i,wc);
        fflush(stdout);
        wc = 0;
        while(str[wc] && !is_space(str[wc]))
            wc++;
        
        result[i] = malloc(sizeof(char) * (wc + 1));
        result[i][wc] = 0;
        int j = 0;
        while(*str && !is_space(*str))
        {
            result[i][j] = *str;
            j++;
            str++;
        }


        while(*str && is_space(*str))
            str++;
        i++;
   }
   return result;
}

int main() {
	char a[] = "s dhjh    dfhds dfhs fshjdhs dhk  ())((^%@^& ";
	char **strs = ft_split(a);
    fflush(stdout);
	while(*strs)
	{
	    printf("%s \n", *strs);
	    strs++;
	}
}
