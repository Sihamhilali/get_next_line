/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:48:26 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/08 10:54:34 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_HBONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *s);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *string);

#endif