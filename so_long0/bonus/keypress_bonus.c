/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:44:06 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 12:23:34 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_map_char(t_playerb *player, t_mapb *map, t_point point, t_bound *b)
{
	t_list	*temp;

	point.y = 0;
	temp = map->map;
	while (temp)
	{
		point.x = -1;
		while (++point.x < map->row)
		{
			point.map_c = *((char *)temp->content + point.x);
			if ((point.y == player->pixel_y - 1) && (point.x == player->pixel_x))
				b->w = map->b_map[player->pixel_y - 1][player->pixel_x];
			else if ((point.y == player->pixel_y) && (point.x == player->pixel_x - 1))
				b->a = map->b_map[player->pixel_y][player->pixel_x - 1];
			else if ((point.y == player->pixel_y + 16) && (point.x == player->pixel_x))
				b->s = map->b_map[player->pixel_y + 16][player->pixel_x];
			else if ((point.y == player->pixel_y) && (point.x == player->pixel_x + 16))
				b->d = map->b_map[player->pixel_y][player->pixel_x +16];
		}
		temp = temp->next;
		point.y++;
	}
}

void	init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->map_c = '\0';
}

int	keypress(int keycode, t_varsb *vars)
{
	t_bound	bound;
	t_point	tmp_p;

	init_point(&tmp_p);
	vars->player->move_flag = 1;
	get_map_char(vars->player, vars->map, tmp_p, &bound);
	if (keycode == KEY_W)
		move_w(vars->player, bound, vars->map, vars);
	else if (keycode == KEY_A)
		move_a(vars->player, bound, vars->map, vars);
	else if (keycode == KEY_S)
		move_s(vars->player, bound, vars->map, vars);
	else if (keycode == KEY_D)
		move_d(vars->player, bound, vars->map, vars);
	else if (keycode == KEY_ESC)
		game_close(vars);
	return (0);
}
