/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:59:37 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/07 15:54:43 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*next(char *str)
{
	int		i;
	char	*ptr;
	int		c;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (!ptr)
		return (NULL);
	i++;
	c = 0;
	while (str[i])
		ptr[c++] = str[i++];
	ptr[c] = '\0';
	// free(str);
	return (ptr);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		s;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	s = 1;
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

char	*get_next_line(int fd)
{
	char	*ptr;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	ptr = next_line(str);
	str = next(str);
	return (ptr);
}

int main()
{
    //int fd = open("siham.txt" , O_RDONLY);
	//printf("%s\n" , get_next_line(fd));
    //return 0;
	//char	*buffer;

	//buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//read(fd, buffer, BUFFER_SIZE);
	//   printf("%s\n" , 	buffer);
    //return 0;
}