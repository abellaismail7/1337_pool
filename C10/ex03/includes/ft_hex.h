/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:39:01 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/14 18:39:01 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEX_H
# define FT_HEX_H

# define FT_STDIN 0
int	ft_read(int bufnb, void *buf, int count);
void	ft_put_hexa(unsigned long nb, int cols);
void	ft_put_content_hexa(unsigned char *str, int size, int cols);
void	ft_put_content(unsigned char *str, int size);
#endif
