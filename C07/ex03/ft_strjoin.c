#include<stdlib.h>
#include<stdio.h>

char *ft_strjoin(int size, char **strs, char *sep)
{   
    int count;
    int sep_count;
    int i;
    int j;
    char *result;

    
    i = 0;
    count = 0;
    sep_count = 0;
    while(sep[sep_count])
        sep_count++;

    while (i < size)
    {
        j = 0;
        while (strs[i][j])
        {
            count++;
            j++;
        }
        if (i != size -1)
            count += sep_count;
        i++;
    }
    count++;
    result = malloc(sizeof(char) * count);
   
    i = 0;
    count = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j])
        {
            result[count++] = strs[i][j];
            j++;
        }
        if (i != size -1)
        {
            j = 0;
            while(sep[j])
            {
                result[count++] = sep[j++];
            }
        }
        i++;
    }

    result[count] = 0;
    
    return result;

}
// testi alklb
int main()
{
    char *s = "\0abc\0edf\0poff";

    char *strs[3] = {s,s+5,s+9};

    char *str = ft_strjoin(3,strs,"--");
    
    printf("%s", str);

    free(str);
}
