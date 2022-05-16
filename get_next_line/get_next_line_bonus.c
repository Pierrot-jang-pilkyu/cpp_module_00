/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:03:31 by pjang             #+#    #+#             */
/*   Updated: 2022/05/16 19:18:36 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[OPEN_MAX];
	char		*temp;

	if (fd >= OPEN_MAX || fd < 0)
		return (NULL);
	temp = NULL;
	division_str(&str[fd], fd);
	if (str[fd] && *str[fd] == '\0')
		return (NULL);
	if (str[fd])
		temp = get_result(&str[fd]);
	return (temp);
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

// void	gnl(int fd, char *expectedString)
// {
// 	char *str;

// 	if (expectedString != NULL)
// 	{
// 		str = get_next_line(fd);
// 		if (ft_strcmp(str, expectedString) == 0)
// 			print_result("OK");
// 		else
// 			print_result("KO");
// 		safe_free(&str);
// 	}
// 	else
// 	{
// 		str = get_next_line(fd);
// 		if (str == expectedString)
// 			print_result("OK");
// 		else
// 			print_result("KO");
// 		safe_free(&str);
// 	}
// }

// int main()
// {
// 	int fd[4];
	
// 	fd[0] = open("gnlTester/files/41_with_nl", O_RDWR);
// 	/* 1 */ gnl(1000, NULL);
// 	/* 2 */ gnl(fd[0], "0123456789012345678901234567890123456789\n");

// 	fd[1] = open("gnlTester/files/42_with_nl", O_RDWR);
// 	/* 3 */ gnl(1001, NULL);
// 	/* 4 */ gnl(fd[1], "01234567890123456789012345678901234567890\n");

// 	fd[2] = open("gnlTester/files/43_with_nl", O_RDWR);
// 	/* 5 */ gnl(1002, NULL);
// 	/* 6 */ gnl(fd[2], "012345678901234567890123456789012345678901\n");

// 	/* 7 */ gnl(1003, NULL);
// 	/* 8 */ gnl(fd[0], "0");

// 	/* 9 */ gnl(1004, NULL);
// 	/* 10 */ gnl(fd[1], "1");

// 	/* 11 */ gnl(1005, NULL);
// 	/* 12 */ gnl(fd[2], "2");

// 	/* 13 */ gnl(fd[0], NULL);
// 	/* 14 */ gnl(fd[1], NULL);
// 	/* 15 */ gnl(fd[2], NULL);

// 	fd[3] = open("gnlTester/files/nl", O_RDWR);
// 	/* 16 */ gnl(1006, NULL);
// 	/* 17 */ gnl(fd[3], "\n");
// 	/* 18 */ gnl(1007, NULL);
// 	/* 19 */ gnl(fd[3], NULL);
// 	write(1, "\n", 1);

	
// }