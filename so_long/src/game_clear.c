/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:06:47 by pjang             #+#    #+#             */
/*   Updated: 2022/09/23 04:10:52 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_clear(t_player *player)
{
	printf("Steps : %d\n", ++player->step);
	printf("\nCongratuation! The game has been cleared.\n\n");
	exit(0);
}
