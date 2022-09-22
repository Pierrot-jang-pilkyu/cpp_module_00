/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by pjang             #+#    #+#             */
/*   Updated: 2022/09/22 21:51:29 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_to_window(t_map *map, t_player *player, t_vars *vars, t_img *img)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img[0].img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, img[1].img, 64, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, img[2].img, 128, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, img[3].img, 0, 64);
	mlx_put_image_to_window(vars->mlx, vars->win, img[4].img, 64, 64);
}

void	img_parsing(t_map *map, t_player *player, t_vars *vars, t_img *img)
{
	int		i;
	char	names[5][31];

	i = 0;
	ft_memcpy(names[0], "../texture/base_sky.xpm\0", 30);
	ft_memcpy(names[1], "../texture/wall_cloud.xpm\0", 30);
	ft_memcpy(names[2], "../texture/collection_star.xpm\0", 31);
	ft_memcpy(names[3], "../texture/player_angel.xpm\0", 30);
	ft_memcpy(names[4], "../texture/escape_hole.xpm\0", 30);
	while (i < 5)
	{
		img[i].img = mlx_xpm_file_to_image(vars->mlx, names[i], \
											&img[i].width, &img[i].high);
		i++;
	}
	img_to_window(map, player, vars, img);
}

void	ft_mlx_img(t_map *map, t_player *player, t_vars *vars)
{
	int		i;
	t_img	img[5];

	i = -1;
	while (++i < 5)
		inits(&img[i], NULL, NULL, NULL);
	img_parsing(map, player, vars, img);
}
