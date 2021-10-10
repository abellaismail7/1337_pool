/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:12:47 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/02 16:40:59 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		g_board_pos[10];
int		g_counter;

int	check_col(int c1, int r1, int c2, int r2)
{
	int	c;
	int	r;

	if (r1 == r2)
		return (1);
	c = c1;
	r = r1;
	while (c < 10 && r < 10)
	{
		c++;
		r++;
		if (c == c2 && r == r2)
			return (1);
	}
	c = c1;
	r = r1;
	while (c >= 0 && r >= 0)
	{
		c++;
		r--;
		if (c == c2 && r == r2)
			return (1);
	}
	return (0);
}

int	check_tab(int n_col)
{
	int	i;
	int	j;
	int	size;

	size = n_col + 1;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (check_col(i, g_board_pos[i], j, g_board_pos[j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	putboard(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = g_board_pos[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	_find_next(int col)
{
	int		i;

	if (col == 10)
	{
		g_counter++;
		putboard();
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		g_board_pos[col] = i;
		if (check_tab(col))
		{
			if (! _find_next(col + 1))
				g_board_pos[col] = -1;
		}
		else
			g_board_pos[col] = -1;
		i++;
	}
	if (g_board_pos[col] == -1)
		return (0);
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	g_counter = 0;
	_find_next(0);
	return (g_counter);
}
//
//#include<stdio.h>
//int main()
//{
//	printf("%d",ft_ten_queens_puzzle());
//}
//
