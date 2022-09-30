/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:00:46 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 21:02:27 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_data(t_data *data)
{
	data->num = 0;
	data->order = 0;
}

void	init_vars(t_list *a, t_vars *vars)
{
	vars->size = ft_lstsize(a);
	vars->pivot = 0;
	vars->k = 0.000000053 * vars->size * vars->size + 0.03 * vars->size + 14.5;
	vars->cmds = 0;
	vars->print = (char *)malloc(sizeof(char) * 1);
	*vars->print = '\0';
}
