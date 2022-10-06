/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:45:07 by pjang             #+#    #+#             */
/*   Updated: 2022/10/06 23:37:53 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_el(t_list **a, t_vars *vars)
{
	int	j;

	j = get_biggest(a);
	if (j == 0)
		sa(a, vars);
}

void	five_big(t_list **a, t_list **b, t_vars *vars)
{
	int	j;

	j = get_biggest(a);
	if (j == 1)
		ra(a, vars);
	if (j == 2)
	{
		ra(a, vars);
		ra(a, vars);
	}
	if (j == 3)
		rra(a, vars);
	pb(a, b, vars);
}

void	five_el_2(t_list **a, t_list **b, int i, t_vars *vars)
{
	if (i == 3)
	{
		rra(a, vars);
		rra(a, vars);
		pb(a, b, vars);
		five_big(a, b, vars);
	}
	if (i == 4)
	{
		rra(a, vars);
		pb(a, b, vars);
		five_big(a, b, vars);
	}
	three_el(a, 1, vars);
	pa(a, b, vars);
	ra(a, vars);
	pa(a, b, vars);
}

void	five_el(t_list **a, t_list **b, t_vars *vars)
{
	int		i;

	i = get_smallest(a);
	if (i == 0)
	{
		pb(a, b, vars);
		five_big(a, b, vars);
	}
	if (i == 1)
	{
		ra(a, vars);
		pb(a, b, vars);
		five_big(a, b, vars);
	}
	if (i == 2)
	{
		ra(a, vars);
		ra(a, vars);
		pb(a, b, vars);
		five_big(a, b, vars);
	}
	five_el_2(a, b, i, vars);
}

void	small_size(t_list **a, t_list **b, t_vars *vars)
{
	int	i;

	i = ft_lstsize(*a);
	if (i == 2)
		two_el(a, vars);
	else if (i == 3)
		three_el(a, 0, vars);
	else if (i == 4)
		four_el(a, b, vars);
	else if (i == 5)
		five_el(a, b, vars);
}
