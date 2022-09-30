/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 08:36:49 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 09:34:49 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_reuslt(t_vars *vars)
{
	ft_putstr_fd(vars->print, 1);
	free(vars->print);
	vars->print = NULL;
}
