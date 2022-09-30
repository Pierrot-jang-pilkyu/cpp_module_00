/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:58:06 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 14:04:34 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list **a, t_list **b, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	tx = *a;
	if (!tx)
	{
		tx = *b;
		ty = tx->next;
		tx->next = NULL;
		*b = ty;
		*a = tx;
	}
	else
	{
		ty = *b;
		tz = ty->next;
		ty->next = tx;
		*a = ty;
		*b = tz;
	}
	vars->cmds++;
	print_re(vars, "pa\n");
}

void	pb(t_list **a, t_list **b, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	tx = *b;
	if (!tx)
	{
		tx = *a;
		ty = tx->next;
		tx->next = NULL;
		*a = ty;
		*b = tx;
	}
	else
	{
		ty = *a;
		tz = ty->next;
		ty->next = tx;
		*b = ty;
		*a = tz;
	}
	vars->cmds++;
	print_re(vars, "pb\n");
}
