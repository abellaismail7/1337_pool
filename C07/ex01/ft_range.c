#include<stdlib.h>

char *ft_range(int min, int max)
{
    int *range;
    int size;
    int i;

    size = max - min;
    if (max <= min)
        return NULL;

    range = malloc(sizeof(int) * size);

    while (min < max)
    {
        range[i] = min;
        min++;
    }
    return range;
    
}
// testi alklb
#include<stdio.h>
int main()
{

}
