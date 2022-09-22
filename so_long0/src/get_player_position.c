/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:54:08 by pjang             #+#    #+#             */
/*   Updated: 2022/09/22 14:57:22 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(t_map *map, t_player *player)
{
	int		i;
	int		j;
	char	c;
	t_list	*temp;

	temp = map->map;
	i = 0;
	while (temp)
	{
		j = 0;
		while (*((char *)temp->content + j))
		{
			c = *((char *)temp->content + j);
			if (c == 'P')
			{
				player->x = i;
				player->y = j;
			}
			j++;
		}
		temp = temp->next;
		i++;
	}
}
