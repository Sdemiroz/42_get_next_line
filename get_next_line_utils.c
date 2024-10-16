/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:23:39 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/10/16 20:45:56 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	x;
	size_t	y;
	size_t	len;

	x = 0;
	y = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	while (s1[x])
	{
		new[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		new[x + y] = s2[y];
		y++;
	}
	new[len] = '\0';
	return (new);
}

size_t	ft_strlen(const char *c)
{
	int	a;

	a = 0;
	while (c[a] != '\0')
		a++;
	return (a);
}

