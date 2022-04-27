/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:03:31 by pjang             #+#    #+#             */
/*   Updated: 2022/04/27 21:41:59 by pjang            ###   ########.fr       */
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

void	refresh(int mode, char **str, char *buffer)
{
	char	*temp;

	if (mode == 1)
	{
		temp = ft_strdup(*str);
		safe_free(str);
		*str = ft_strjoin(temp, buffer);
		safe_free(&temp);
	}
	if (mode == 2)
	{
		safe_free(str);
		*str = ft_strdup(buffer);
	}
}

int	is_division(long long idx, char **s1, char **s2, char **s3)
{
	char	*temp;
	char	*buffer;

	buffer = *s2;
	if (idx != -1)
	{
		temp = ft_substr(buffer, 0, idx + 1);
		if (*s1[0] == '\n')
			*s3 = ft_strjoin(*s1 + 1, temp);
		else
			*s3 = ft_strjoin(*s1, temp);
		safe_free(&temp);
		refresh(2, s1, buffer + idx);
		return (1);
	}
	if (s1[0][0] == '\n' && s1[0][1] == '\0')
	{
		safe_free(s1);
		refresh(1, s1, buffer);
	}
	else
		refresh(1, s1, buffer);
	return (0);
}

char	*division_str(char **str, int fd)
{
	char		*buffer;
	char		*result;
	long long	f_len;

	if (*str == 0x00)
		*str = ft_strdup("");
	result = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*buffer = '\0';
	while (1)
	{
		f_len = read(fd, buffer, BUFFER_SIZE);
		if (f_len == 0 || f_len == -1)
			break ;
		buffer[f_len] = '\0';
		if (is_division(get_index(buffer), str, &buffer, &result))
			break ;
	}
	if (f_len == -1 || (f_len == 0 && (**str == '\0' || *buffer == '\0')))
		safe_free(str);
	safe_free(&buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;
	char		*result;

	if (fd > 8192)
		return (NULL);
	temp = NULL;
	if (str && str[0] == '\n' && str[1] != '\0')
		temp = ft_strdup(str + 1);
	result = division_str(&str, fd);
	if (!result)
	{
		if (temp && !str)
			return (temp);
		return (ft_strdup(str));
	}
	return (result);
}

// #include <fcntl.h>

// void	print_result(char *str)
// {
// 	write(1, str, ft_strlen(str));
// 	write(1, "\n", 1);
// }

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	size_t			i;
// 	unsigned char	*t1;
// 	unsigned char	*t2;

// 	i = 0;
// 	t1 = (unsigned char *)s1;
// 	t2 = (unsigned char *)s2;
// 	while (t1[i] && t2[i] && t1[i] == t2[i])
// 		i++;
// 	return (t1[i] - t2[i]);
// }

// int main()
// {
// 	int fd;
// 	char *str;

// 	fd = open("gnlTester/files/41_with_nl", O_RDWR);
// 	/* 1 */ str = get_next_line(fd);
// 	if (ft_strcmp(str, "0123456789012345678901234567890123456789\n") == 0)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// 	safe_free(&str);
// 	/* 2 */ str = get_next_line(fd);
// 	if (ft_strcmp(str, "0") == 0)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// 	safe_free(&str);
// 	/* 3 */ str = get_next_line(fd);
// 	if (str == NULL)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// //	safe_free(&str);
// 	close(fd);
	
// }