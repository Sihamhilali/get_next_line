/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:03:37 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/08 14:31:57 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*copied;
	char	*becopied;
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	copied = (char *) dest;
	becopied = (char *) src;
	while (i < n)
	{
		copied[i] = becopied[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *string)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * ft_strlen(string)+1);
	if (!ptr)
		return (NULL);
	while (string[i])
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)
	{
		while (n-- > 0)
		{
			d[n] = s[n];
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr1;
	size_t	j;

	if (!s1)
		s1 = ft_strdup("");
	j = ft_strlen(s1) + ft_strlen(s2);
	ptr1 = malloc (j + 1);
	if (!ptr1)
		return (NULL);
	ft_memmove(ptr1, s1, ft_strlen(s1));
	ft_memmove(ptr1 + ft_strlen(s1), s2, ft_strlen(s2));
	ptr1[j] = '\0';
	//free(s1);
	s1 = 0;
	return (ptr1);
}
