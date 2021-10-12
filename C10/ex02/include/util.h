/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:27:06 by iait-bel          #+#    #+#             */
/*   Updated: 2021/10/12 18:27:06 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

int		ft_strlen(char *str);
int		tail_file(char *filename, int count, int is_multi);
void	tail_buf(int buf, int count);
void	tail_stdin(int count);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);

#endif
