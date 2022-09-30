/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:43:30 by pjang             #+#    #+#             */
/*   Updated: 2022/09/29 16:43:32 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mpitw(t_map *map, t_player *player, t_vars *vars, t_point point)
{
	if (point.map_c == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
			map->img_base.img, point.x * 64, point.y * 64);
	}
	else if (point.map_c == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
			map->img_wall.img, point.x * 64, point.y * 64);
	}
	else if (point.map_c == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
			map->img_col.img, point.x * 64, point.y * 64);
	}
	else if (point.map_c == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
			map->img_esc.img, point.x * 64, point.y * 64);
	}
	else if (point.map_c == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
			map->img_play.img, player->x * 64, player->y * 64);
	}
}

void	img_to_window(t_map *map, t_player *player, t_vars *vars)
{
	t_point	point;
	t_list	*temp;

	temp = map->map;
	point.y = 0;
	while (temp)
	{
		point.x = -1;
		while (++point.x < map->row)
		{
			point.map_c = *((char *)temp->content + point.x);
			mpitw(map, player, vars, point);
		}
		temp = temp->next;
		point.y++;
	}
}

void	ft_mlx_img(t_map *map, t_player *player, t_vars *vars)
{
	char	col[30];

	ft_memcpy(col, "texture/collection_star.xpm", 31);
	map->img_base.img = mlx_xpm_file_to_image(vars->mlx, \
	"texture/base_sky.xpm", &map->img_base.width, &map->img_base.height);
	map->img_wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"texture/wall_cloud.xpm", &map->img_wall.width, &map->img_wall.height);
	map->img_col.img = mlx_xpm_file_to_image(vars->mlx, \
	col, &map->img_col.width, &map->img_col.height);
	map->img_play.img = mlx_xpm_file_to_image(vars->mlx, \
	"texture/player_angel.xpm", &map->img_play.width, &map->img_play.height);
	map->img_esc.img = mlx_xpm_file_to_image(vars->mlx, \
	"texture/escape_hole.xpm", &map->img_esc.width, &map->img_esc.height);
	img_to_window(map, player, vars);
	vars->map = map;
	vars->player = player;
}
