/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 04:06:07 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 15:32:24 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	file_check(const char *filename)
{
	int		len;
	char	*temp;

	len = ft_strlen(filename);
	temp = ft_substr(filename, len - 4, 4);
	if (ft_strncmp((const char *)temp, ".ber", 4) != 0)
		put_error("The file extension is incorrect.");
	free(temp);
}

void	del_newline(t_map *map)
{
	int		len;
	t_list	*temp;
	char	*str;

	temp = map->map;
	str = (char *)temp->content;
	while (temp)
	{
		len = get_linelen((char *)temp->content);
		*((char *)temp->content + len) = '\0';
		temp = temp->next;
		map->col++;
	}
}

void	get_map(t_map *map)
{
	int		fd;
	int		i;
	char	*temp;

	i = -1;
	file_check(map->filename);
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		put_error("fd(-1) : File open failure.");
	temp = get_next_line(fd);
	if (!temp)
		put_error("Empty file.");
	ft_lstadd_back(&map->map, ft_lstnew((void *)temp));
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		ft_lstadd_back(&map->map, ft_lstnew((void *)temp));
	}
	map->row = get_linelen((char *)map->map->content);
	del_newline(map);
	map_check(map);
	close(fd);
}
