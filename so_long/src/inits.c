/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:45:54 by pjang             #+#    #+#             */
/*   Updated: 2022/09/23 03:49:20 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->width = 0;
	img->height = 0;
}

void	init_player(t_player *player)
{
	player->success_flag = 0;
	player->x = 0;
	player->y = 0;
	player->step = 0;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->filename = "";
	map->row = 0;
	map->col = 0;
	map->p_num = 0;
	map->c_num = 0;
	map->e_num = 0;
	init_img(&map->img_base);
	init_img(&map->img_wall);
	init_img(&map->img_col);
	init_img(&map->img_play);
	init_img(&map->img_esc);
}

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->player = NULL;
}

void	inits(t_player *player, t_map *map, t_vars *vars)
{
	if (player != NULL)
		init_player(player);
	if (map != NULL)
		init_map(map);
	if (vars != NULL)
		init_vars(vars);
}
