/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:47:00 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/17 19:49:57 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*full_file(char *txt)
{
	int		i;
	char	*typ;

	i = 0;
	if (!txt[i])
		return (NULL);
	while (txt[i] && txt[i] != '\n')
		i++;
	typ = (char *)malloc(sizeof(char) * (i + 2));
	if (!typ)
		return (0);
	i = -1;
	while (txt[++i] && txt[i] != '\n')
		typ[i] = txt[i];
	if (txt[i] == '\n')
	{
		typ[i] = txt[i];
		i++;
	}
	typ[i] = '\0';
	return (typ);
}

void	ft_free(void **fre)
{
	free(*fre);
	*fre = NULL;
}

char	*full_line(char *txt)
{
	int		i;
	char	*string;

	i = 0;
	while (txt[i] != '\n' && txt[i] != '\0')
		i++;
	if (txt[i] == '\0')
		return (ft_free((void **)&txt), NULL);
	string = ft_substr(txt, i + 1, ft_strlen(txt) - i);
	ft_free((void **)&txt);
	if (!string)
		return (NULL);
	if (*string == '\0')
	{
		ft_free((void **)&string);
		return (NULL);
	}
	return (string);
}

char	*get_next_line(int fd)
{
	char		*typ;
	char		*buffer;
	int			size;
	static char	*tx[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(tx[fd], '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (ft_free((void **)&buffer), ft_free((void **)&tx[fd]), NULL);
		buffer[size] = '\0';
		tx[fd] = ft_strjoin(tx[fd], buffer);
	}
	ft_free((void **)&buffer);
	if (!tx[fd][0] || !tx[fd])
		return (ft_free((void **)&tx[fd]), tx[fd] = NULL);
	typ = full_file(tx[fd]);
	tx[fd] = full_line(tx[fd]);
	return (typ);
}
