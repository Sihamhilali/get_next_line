/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:56:07 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/07 20:06:34 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_read(int fd, char *str)
{
	int		s;
	char	*ptr;

	s = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buffer)
		return (0);
	while (s != 0 && ft_strchr(str, '\n') == NULL)
	{
		s = read(fd, buffer, BUFFER_SIZE);
		if (s == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[s] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*line(char str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	while (!str && str[i] != '\n')
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (!str[i])
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';
	return (ptr);
}
