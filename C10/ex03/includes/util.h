/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:39:01 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/14 18:39:01 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

typedef struct s_ft_options
{
    char *basename;
    int cols;
    char **files;
    int size;
}   t_ft_options;

int	    open_file(char *filename, char *basename);
void	dump_buf(int cols);
void	dump_file(int *add, int fp, int cols);
int     dump_files(t_ft_options op);
#endif
