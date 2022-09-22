/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:45:54 by pjang             #+#    #+#             */
/*   Updated: 2022/09/22 19:11:16 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->width = 0;
	img->high = 0;
}

void	init_player(t_player *player)
{
	player->sucess_flag = 0;
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
}

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
}

void	inits(t_img *img, t_player *player, t_map *map, t_vars *vars)
{
	if (img != NULL)
		init_img(img);
	if (player != NULL)
		init_player(player);
	if (map != NULL)
		init_map(map);
	if (vars != NULL)
		init_vars(vars);
}
