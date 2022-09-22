/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:44:13 by pjang             #+#    #+#             */
/*   Updated: 2022/09/22 21:43:46 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx_opengl/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
// mlx.h에선 mlx_*_hook함수들은 mlx_hook을 통해서 공통적인 형식으로 이용할 수 있다.
// int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
// 인자인 x_event, x_mask에 해당하는 인자는 X.h에 존재하는 event, mask 값을 사용한다.
// mac os에선 x_mask를 사용하지 않는다. 리눅스에서는 x_mask가 필요하다.
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
// key 옆의 숫자는 Key code of mac os이다. 
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}					t_vars;

typedef struct s_img
{
	void	*img;
	int		width;
	int		high;
}					t_img;

typedef struct s_player
{
	int	sucess_flag;
	int	x;
	int	y;
	int	step;
}					t_player;

typedef struct s_map
{
	t_list		*map;
	const char	*filename;
	int			row;
	int			col;
	int			p_num;
	int			c_num;
	int			e_num;
}					t_map;

void	ft_mlx_img(t_map *map, t_player *player, t_vars *vars);
void	keypress(int keycode, t_vars *vars, t_player *player, t_map *map);

// struct init
void	inits(t_img *img, t_player *player, t_map *map, t_vars *vars);

// valid
void	map_check(t_map *map);

// parsing
int		get_linelen(char *map_line);
void	get_map(t_map *map);
void	get_player_position(t_map *map, t_player *player);

void	put_error(char *message);

#endif