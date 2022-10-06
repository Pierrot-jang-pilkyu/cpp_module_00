/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:10:50 by pjang             #+#    #+#             */
/*   Updated: 2022/10/07 01:21:44 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*a)
	{
		tx = *a;
		ty = tx->next;
		tz = ft_lstlast(tx);
		tx->next = NULL;
		tz->next = tx;
		*a = ty;
	}
	vars->cmds++;
	print_re(vars, "ra\n");
}

void	rb(t_list **b, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*b)
	{
		tx = *b;
		ty = tx->next;
		tz = ft_lstlast(tx);
		tx->next = NULL;
		tz->next = tx;
		*b = ty;
	}
	vars->cmds++;
	print_re(vars, "rb\n");
}

void	rr(t_list **a, t_list **b, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*a)
	{
		tx = *a;
		ty = tx->next;
		tz = ft_lstlast(tx);
		tx->next = NULL;
		tz->next = tx;
		*a = ty;
	}
	if (*b)
	{
		tx = *b;
		ty = tx->next;
		tz = ft_lstlast(tx);
		tx->next = NULL;
		tz->next = tx;
		*b = ty;
	}
	vars->cmds++;
	print_re(vars, "rr\n");
}
