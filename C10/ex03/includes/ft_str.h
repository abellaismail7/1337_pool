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

#ifndef FT_STR_H
# define FT_STR_H

int ft_strlen(char *str);    
unsigned char	*ft_strncpy(unsigned char *dest,
	unsigned char *src, unsigned int n);
int	ft_strncmp(unsigned char *s1, unsigned char *s2, unsigned int n);
int	ft_strcmp(char *s1, char *s2);

#endif
