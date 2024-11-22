/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:00:38 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/10/21 15:07:33 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	ft_bzero(void *a, size_t len)
{
	unsigned char	*x;

	x = (unsigned char *)a;
	while (len > 0)
	{
		*x = '\0';
		len--;
		x++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*x;

	if (num == 0 || size == 0)
		return (NULL);
	x = malloc(num * size);
	if (!x)
		return (NULL);
	ft_bzero(x, num * size);
	return (x);
}
