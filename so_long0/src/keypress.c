/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:44:06 by pjang             #+#    #+#             */
/*   Updated: 2022/09/22 20:45:07 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Hooking은 소프트웨어 공학 용어로, 운영 체제나 응용 소프트웨어 등의 각종 컴퓨터 프로그램에서
// 소프트웨어 구성 요소 간에 발생하는 함수 호출, 메시지, 이벤트 등을 중간에서 바꾸거나
// 가로채는 명령, 방법, 기술이나 행위를 말한다.
// mlx를 사용하면서 생길 후킹은 마우스 클릭이나 자판 입력을 감지하고 가져온다 생각해도 무방하다.
// 이벤트 발생시 호출될 함수
void	keypress(int keycode, t_vars *vars, t_player *player, t_map *map)
{
	if (keycode == KEY_W)
	{
		player->y++;
		printf("Step : %d\n", ++player->step);
	}
	else if (keycode == KEY_A)
	{
		player->x--;
		printf("Step : %d\n", ++player->step);
	}
	else if (keycode == KEY_S)
	{
		player->y--;
		printf("Step : %d\n", ++player->step);
	}
	else if (keycode == KEY_D)
	{
		player->x++;
		printf("Step : %d\n", ++player->step);
	}
	else if (keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
}
