/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:00:34 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/10/21 15:11:54 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_join(char *temp, char *buffer)
{
	char	*result;

	result = ft_strjoin(temp, buffer);
	free (temp);
	return (result);
}

static char	*ft_get_rest(char *buffer)
{
	char	*rest;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (buffer[x] && buffer [x] != '\n')
		x++;
	if (!buffer[x])
	{
		free(buffer);
		return (NULL);
	}
	rest = ft_calloc(ft_strlen(buffer) - x + 1, sizeof(char));
	if (!rest)
		return (NULL);
	while (buffer[++x])
		rest[y++] = buffer[x];
	rest[y] = '\0';
	free(buffer);
	return (rest);
}

static char	*ft_get_res(char *buffer)
{
	int		i;
	char	*res;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (ft_strchr(buffer, '\n'))
		res = ft_calloc((i + 2), 1);
	else
		res = ft_calloc((i + 1), 1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer [i] == '\n')
		res[i++] = '\n';
	return (res);
}

static char	*ft_get_buffer(int fd, char *buffer)
{
	char	*temp;
	int		cc;

	cc = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!temp)
		return (NULL);
	while (cc > 0)
	{
		cc = read(fd, temp, BUFFER_SIZE);
		if (cc == -1)
		{
			free (temp);
			free (buffer);
			return (NULL);
		}
		temp[cc] = '\0';
		buffer = ft_join(buffer, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_get_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	res = ft_get_res(buffer[fd]);
	buffer[fd] = ft_get_rest(buffer[fd]);
	return (res);
}
