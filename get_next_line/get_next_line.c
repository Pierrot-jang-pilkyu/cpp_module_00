/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:03:31 by pjang             #+#    #+#             */
/*   Updated: 2022/05/16 18:47:49 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	safe_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	refresh(long long mode, char **str, char **buffer, char *temp)
{
	long long	idx;

	if (mode == 1)
	{
		temp = ft_strdup(*str);
		safe_free(str);
		*str = ft_strjoin(temp, *buffer);
		safe_free(&temp);
	}
	if (mode == 2)
	{
		temp = ft_strdup(*str);
		safe_free(str);
		idx = get_index(temp);
		*str = ft_substr(temp, idx + 1, ft_strlen(temp) - idx);
		safe_free(&temp);
	}
}

void	division_str(char **str, int fd)
{
	char		*buffer;
	long long	f_len;

	if (*str == 0x00)
		*str = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	*buffer = '\0';
	while (1)
	{
		f_len = read(fd, buffer, BUFFER_SIZE);
		if (f_len == 0 || f_len == -1)
			break ;
		buffer[f_len] = '\0';
		refresh(1, str, &buffer, NULL);
		if (get_index(buffer) != -1)
			break ;
	}
	if (f_len == -1 || (f_len == 0 && **str == '\0'))
		safe_free(str);
	safe_free(&buffer);
}

char	*get_result(char **str)
{
	char		*temp;
	long long	idx;

	temp = NULL;
	if (*str)
	{
		idx = get_index(*str);
		if (idx != -1)
		{
			temp = ft_substr(*str, 0, idx + 1);
			refresh(2, str, NULL, NULL);
		}
		else
		{
			temp = ft_strdup(*str);
			safe_free(str);
		}
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;

	if (fd >= OPEN_MAX)
		return (NULL);
	temp = NULL;
	division_str(&str, fd);
	if (str && *str == '\0')
		return (NULL);
	if (str)
		temp = get_result(&str);
	return (temp);
}
