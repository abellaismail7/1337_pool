#include<stdlib.h>

int ft_range_ultimate(int **range, int min, int max)
{
    int size;
    int i;

    size = max - min;
    if (max <= min)
    {
        *range = NULL;
        return 0;
    }

    *range = malloc(sizeof(int) * size);

    i = 0;
    while (min < max)
    {
        (*range)[i] = min;
        min++;
        i++;
    }
    return size;
    
}
// testi alklb
#include<stdio.h>
int main()
{

}
