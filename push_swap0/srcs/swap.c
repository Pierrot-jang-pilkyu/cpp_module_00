/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:19:52 by pjang             #+#    #+#             */
/*   Updated: 2022/10/07 01:20:49 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **a, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*a)
	{
		tx = *a;
		ty = tx->next;
		tz = ty->next;
		tx->next = tz;
		ty->next = tx;
		*a = ty;
	}
	vars->cmds++;
	print_re(vars, "sa\n");
}

void	sb(t_list **b, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*b)
	{
		tx = *b;
		ty = tx->next;
		tz = ty->next;
		tx->next = tz;
		ty->next = tx;
		*b = ty;
	}
	vars->cmds++;
	print_re(vars, "sb\n");
}

void	ss(t_list **a, t_list **b, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*a)
	{
		tx = *a;
		ty = tx->next;
		tz = ty->next;
		tx->next = tz;
		ty->next = tx;
		*a = ty;
	}
	if (*b)
	{
		tx = *b;
		ty = tx->next;
		tz = ty->next;
		tx->next = tz;
		ty->next = tx;
		*b = ty;
	}
	vars->cmds++;
	print_re(vars, "ss\n");
}
