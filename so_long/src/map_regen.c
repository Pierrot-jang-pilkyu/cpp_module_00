/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_regen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:33:06 by pjang             #+#    #+#             */
/*   Updated: 2022/09/23 02:25:51 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_regen(t_map *map, t_player *pl, t_point p)
{
	t_point	tmp_p;
	t_list	*temp;

	temp = map->map;
	tmp_p.y = -1;
	while (++tmp_p.y < map->col)
	{
		tmp_p.x = -1;
		while (++tmp_p.x < map->row)
		{
			if (tmp_p.x == pl->x && tmp_p.y == pl->y)
				*((char *)temp->content + tmp_p.x) = 'P';
			if (tmp_p.x == p.x && tmp_p.y == p.y)
				*((char *)temp->content + tmp_p.x) = '0';
		}
		temp = temp->next;
	}
}
