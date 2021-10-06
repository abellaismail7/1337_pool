#include "ft_stock_str.h"
struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	struct s_stock_str *stocks;

	stocks = malloc((ac + 1) * sizeof(struct s_stock_str));	
	stocks[ac] = 0;
	i = 0;
	while(i < ac)
	{
		stocks[i].size = ft_strlen(av[i]);
		stocks[i].str = av[i];
		stocks[i].copy = ft_strdup(av[i]);
	}
	return stocks;
}
