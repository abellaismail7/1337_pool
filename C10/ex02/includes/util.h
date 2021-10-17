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

int	    tail_file(char *filename, int count, int is_multi, char *basename);
int	    ft_read(int bufnb, void *buf, int count);
void	tail_buf(int bufnb, int count);

#endif
