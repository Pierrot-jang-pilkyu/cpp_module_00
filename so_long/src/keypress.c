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

#include "../includes/so_long.h"

void	get_map_char(t_player *player, t_map *map, t_point point, t_bound *b)
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
			if ((point.y == player->y - 1) && (point.x == player->x))
				b->w = point.map_c;
			else if ((point.y == player->y) && (point.x == player->x - 1))
				b->a = point.map_c;
			else if ((point.y == player->y + 1) && (point.x == player->x))
				b->s = point.map_c;
			else if ((point.y == player->y) && (point.x == player->x + 1))
				b->d = point.map_c;
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

int	keypress(int keycode, t_vars *vars)
{
	t_bound	bound;
	t_point	tmp_p;

	init_point(&tmp_p);
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
