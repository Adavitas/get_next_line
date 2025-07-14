/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobu <nobu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:52:07 by nobu              #+#    #+#             */
/*   Updated: 2025/07/13 02:04:43 by nobu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);char	*ft_strdup(const char *s)
	if (dst == NULL || src == NULL || !size)
		return (len);
	while (*src && --size)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		buffer_size;

	buffer_size = ft_strlen(s) + 1;
	str = malloc(buffer_size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, buffer_size);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}
