/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:00:13 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 10:04:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_gnl.h"

static char	*ft_free(char *res, char *buf, int ret)
{
	char	*tmp;

	buf[ret] = '\0';
	tmp = ft_strjoin_gnl(res, buf);
	free(res);
	return (tmp);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = f_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	i++;
	line[i] = '\0';
	return (line);
}

static char	*ft_next(char *buffer)
{
	char	*buf;
	int		start;
	int		i;

	start = 0;
	while (buffer[start] && buffer[start] != '\n')
		start++;
	if (!buffer[start++])
	{
		free(buffer);
		return (NULL);
	}
	buf = f_calloc(sizeof(char), (ft_strlen(buffer) - start + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (buffer[start])
	{
		buf[i] = buffer[start];
		start++;
		i++;
	}
	buf[i] = '\0';
	free(buffer);
	return (buf);
}

static char	*ft_readfile(int fd, char *res, int ret)
{
	char	*buf;

	if (!res)
		res = f_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(res);
			free(buf);
			return (NULL);
		}
		res = ft_free(res, buf, ret);
		if (ft_strchr_index(buf, '\n') != -1)
			break ;
	}
	free(buf);
	return (res);
}

char	*ft_gnl(int fd, int delete)
{
	static	char	*(buffer[1024]);
	char			*line;

	if (delete == 1)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_readfile(fd, buffer[fd], 1);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	if (buffer[fd] == NULL && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
