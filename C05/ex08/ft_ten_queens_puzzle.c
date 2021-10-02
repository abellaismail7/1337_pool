/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:12:47 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/02 12:53:35 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_board_pos[10];

int check_col(int c1, int r1,int c2, int r2)
{
	if (r1 == r2)
		return 1;
	while(c1 < 10 && r1 < 10)
	{
		c1++;
		r1++;
		if(c1 == c2 && r1 == r2)
			return 1;
	}
	return 0;
}

int check_tab(int n_col){
	int i;

	i = 0;
	while(i < n_col)
	{
		if(check_col(i,g_board_pos[i],i+1,g_board_pos[i+1]))
		{
			return 0;
		}
	}

	return 1;
}

int _ft_len_queens_puzzle(int col)
{
	int i;

	i = 0;
	while(i < 9){
		g_board_pos[col] = i;
		if(check_tab(col))
		{
			if(!_ft_len_queens_puzzle(col+1))
			{
				i++;	
			}
		}
		else
			i++;
			
	}

	return 1;
}
int ft_len_queens_puzzle(void)
{
	_ft_len_queens_puzzle(0);
	return 1;
}

int main()
{
	return check_col(1,0,9,9);
}
