/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:05:23 by pjang             #+#    #+#             */
/*   Updated: 2022/10/07 05:22:35 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	putstr_to_window(t_varsb *vars, t_playerb *pl)
{
	char	*str;

	str = ft_strjoin("Steps : ", ft_itoa(pl->step));
	mlx_string_put(vars->map, vars->win, 32, 32, 0xFF, str);
	free(str);
	str = NULL;
}

void	move_w(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars)
{
	t_point	tmp_p;

	if (b.w == 'E' && pl->success_flag)
		game_clear(pl);
	else if (b.w == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	if (b.w == '0' || b.w == 'C')
	{
		pl->pixel_y--;
		pl->py_step--;
		map_regen(map, pl, tmp_p);
		
		if (pl->py_step == -16 || pl->py_step == 16)
			printf("Steps : %d\n", ++pl->step);
		ft_mlx_img(map, pl, vars);
		putstr_to_window(vars, pl);
	}
}

void	move_a(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars)
{
	t_point	tmp_p;

	if (b.a == 'E' && pl->success_flag)
		game_clear(pl);
	else if (b.a == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	if (b.a == '0' || b.a == 'C')
	{
		pl->pixel_x--;
		pl->px_step--;
		map_regen(map, pl, tmp_p);
		if (pl->px_step == -16 || pl->px_step == 16)
			printf("Steps : %d\n", ++pl->step);
		ft_mlx_img(map, pl, vars);
		putstr_to_window(vars, pl);
	}
}

void	move_s(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars)
{
	t_point	tmp_p;

	if (b.s == 'E' && pl->success_flag)
		game_clear(pl);
	else if (b.s == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	if (b.s == '0' || b.s == 'C')
	{
		pl->pixel_y++;
		pl->py_step++;
		map_regen(map, pl, tmp_p);
		if (pl->py_step == -16 || pl->py_step == 16)
			printf("Steps : %d\n", ++pl->step);
		ft_mlx_img(map, pl, vars);
		putstr_to_window(vars, pl);
	}
}

void	move_d(t_playerb *pl, t_bound b, t_mapb *map, t_varsb *vars)
{
	t_point	tmp_p;

	if (b.d == 'E' && pl->success_flag)
		game_clear(pl);
	else if (b.d == 'C')
	{
		if (--map->c_num == 0)
			pl->success_flag = 1;
	}
	if (b.d == '0' || b.d == 'C')
	{
		pl->pixel_x++;
		pl->px_step++;
		map_regen(map, pl, tmp_p);
		if (pl->px_step == -16 || pl->px_step == 16)
			printf("Steps : %d\n", ++pl->step);
		ft_mlx_img(map, pl, vars);
		putstr_to_window(vars, pl);
	}
}
