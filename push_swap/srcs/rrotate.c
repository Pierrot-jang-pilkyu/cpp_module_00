/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:10:50 by pjang             #+#    #+#             */
/*   Updated: 2022/10/07 00:59:10 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*get_before(t_list *list)
{
	int		size;
	t_list	*t;

	size = ft_lstsize(list);
	t = list;
	while (--size > 1)
	{
		t = t->next;
	}
	return (t);
}

void	rra(t_list **a, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*a)
	{
		tx = *a;
		ty = get_before(tx);
		tz = ft_lstlast(tx);
		ty->next = NULL;
		tz->next = tx;
		*a = tz;
		vars->cmds++;
	}
	print_re(vars, "rra\n");
}

void	rrb(t_list **b, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*b)
	{
		tx = *b;
		ty = get_before(tx);
		tz = ft_lstlast(tx);
		ty->next = NULL;
		tz->next = tx;
		*b = tz;
	}
	vars->cmds++;
	print_re(vars, "rrb\n");
}

void	rrr(t_list **a, t_list **b, t_vars *vars)
{
	t_list	*tx;
	t_list	*ty;
	t_list	*tz;

	if (*a)
	{
		tx = *a;
		ty = get_before(tx);
		tz = ft_lstlast(tx);
		ty->next = NULL;
		tz->next = tx;
		*a = tz;
	}
	if (*b)
	{
		tx = *b;
		ty = get_before(tx);
		tz = ft_lstlast(tx);
		ty->next = NULL;
		tz->next = tx;
		*b = tz;
	}
	vars->cmds++;
	print_re(vars, "rrr\n");
}
