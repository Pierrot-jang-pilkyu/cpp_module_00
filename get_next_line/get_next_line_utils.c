/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:03:46 by pjang             #+#    #+#             */
/*   Updated: 2022/04/27 21:40:10 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	get_index(char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	int		s_len;
	char	*buf;
	char	*dst;

	if (!s1)
		return (NULL);
	s_len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (NULL);
	buf = dst;
	while (*s1)
		*buf++ = *s1++;
	*buf = '\0';
	return (dst);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*buf;
	char	*sub;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len >= len)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else
		sub = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (!sub)
		return (NULL);
	buf = sub;
	while (s[start + i] && i < len)
	{
		*buf++ = s[start + i];
		i++;
	}
	*buf = '\0';
	return (sub);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buf;
	char	*join;

	if (!s1)
		return (ft_strdup(s2));
	join = (char *)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	buf = join;
	while (*s1)
		*buf++ = *s1++;
	while (*s2)
		*buf++ = *s2++;
	*buf = '\0';
	return (join);
}
