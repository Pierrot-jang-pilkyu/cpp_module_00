/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:44:04 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 12:23:32 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	char		*title;
	t_map		map;
	t_player	player;
	t_vars		vars;

	if (argc == 2)
	{
		inits(&player, &map, &vars);
		map.filename = argv[1];
		get_map(&map);
		get_player_position(&map, &player);
		title = "ANGEL IN THE HEAVEN";
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, map.row * 64, map.col * 64, title);
		ft_mlx_img(&map, &player, &vars);
		mlx_hook(vars.win, X_EVENT_KEY_PRESS, 0, &keypress, &vars);
		mlx_hook(vars.win, X_EVENT_DESTROY_NOTIFY, 0, &game_close, &vars);
		mlx_loop(vars.mlx);
	}
	else
		put_error("Only One argument is required.");
	return (0);
}
