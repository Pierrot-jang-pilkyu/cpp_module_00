/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:54:40 by pjang             #+#    #+#             */
/*   Updated: 2022/04/18 14:00:17 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*buf;
	char	*sub;

	i = 0;
	s_len = ft_strlen((char *)s);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start >= s_len)
		return (sub);
	buf = sub;
	while (s[start + i] && i < len)
	{
		*buf++ = s[start + i];
		i++;
	}
	*buf = '\0';
	return (sub);
}
