/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:23:42 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/10/16 20:50:57 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join(char *temp, char *buffer)
{
	char	*result;

	result = ft_strjoin(temp, buffer);
	free (temp);
	return (result);
}

static char	*ft_get_buffer(int fd, char *buffer)
{
	char	*temp;
	size_t	cc;

	cc = 1;
	if (!buffer)
		buffer = malloc(1);
	temp = malloc(BUFFER_SIZE + 1);
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
		if (ft_strnchr(temp, '\n'))
			break ;
	}
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_buffer(fd, buffer);
	return (res);
}
