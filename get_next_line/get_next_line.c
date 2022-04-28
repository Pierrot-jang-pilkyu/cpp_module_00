/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:03:31 by pjang             #+#    #+#             */
/*   Updated: 2022/04/28 17:28:34 by pjang            ###   ########.fr       */
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
	if (mode == -1)
	{
		temp = ft_strdup(*str);
		safe_free(str);
		*str = ft_strjoin(temp, *buffer);
		safe_free(&temp);
	}
	else if (mode == -2)
	{
		safe_free(str);
		*str = ft_strdup(*buffer);
	}
	else if (mode >= 0)
	{
		temp = ft_substr(*buffer, 0, mode + 1);
		*str = ft_substr(*buffer, mode, ft_strlen(*buffer));
		safe_free(buffer);
		*buffer = temp;
	}
	if (mode > -3)
		return ;
	safe_free(str);
	*str = ft_strdup(temp);
	safe_free(&temp);
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
		buffer += idx;
		refresh(-2, s1, &buffer, NULL);
		return (1);
	}
	if (s1[0][0] == '\n' && s1[0][1] == '\0')
	{
		safe_free(s1);
		refresh(-1, s1, &buffer, NULL);
	}
	else
		refresh(-1, s1, &buffer, NULL);
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
		{
			if (get_index(temp) != -1)
				refresh(get_index(temp), &str, &temp, NULL);
			return (temp);
		}
		safe_free(&temp);
		if (str && *str == '\n')
			refresh(-3, &str, &temp, ft_strdup(str + 1));
		return (ft_strdup(str));
	}
	safe_free(&temp);
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

// 	fd = open("gnlTester/files/multiple_line_no_nl", O_RDWR);
// 	/* 1 */ str = get_next_line(fd);
// 	if (ft_strcmp(str, "01234567890123456789012345678901234567890\n") == 0)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// 	safe_free(&str);
// 	/* 2 */ str = get_next_line(fd);
// 	if (ft_strcmp(str, "987654321098765432109876543210987654321098\n") == 0)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// 	safe_free(&str);
// 	/* 3 */ str = get_next_line(fd);
// 	if (ft_strcmp(str, "0123456789012345678901234567890123456789012\n") == 0)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// 	safe_free(&str);
// 	/* 4 */ str = get_next_line(fd);
// 	if (ft_strcmp(str, "987654321098765432109876543210987654321098\n") == 0)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// 	safe_free(&str);
// 	/* 5 */ str = get_next_line(fd);
// 	if (ft_strcmp(str, "01234567890123456789012345678901234567890") == 0)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// 	safe_free(&str);
// 	/* 6 */ str = get_next_line(fd);
// 	if (str == NULL)
// 		print_result("OK");
// 	else
// 		print_result("KO");
// 	safe_free(&str);
// 	close(fd);
	
// }