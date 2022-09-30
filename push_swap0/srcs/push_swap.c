/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 00:11:14 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 21:18:59 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_to_b(t_list **a, t_list **b, t_vars *vars)
{
	t_data	*dummy;
	t_list	*temp;

	while (ft_lstsize(*a) != 0)
	{
		temp = *a;
		dummy = (t_data *)temp->content;
		if (dummy->order <= vars->pivot)
			pb(a, b, vars);
		else if (dummy->order < (vars->pivot + vars->k))
		{
			pb(a, b, vars);
			if (ft_lstsize(*b) != 1)
				rb(b, vars);
		}
		else if ((vars->pivot + vars->k) <= dummy->order && ft_lstsize(*a) != 1)
		{
			ra(a, vars);
			vars->pivot--;
		}
		vars->pivot++;
	}
}

void	a_to_b2(t_list **a, t_list **b, t_vars *vars)
{
	t_data	*dummy;
	t_list	*temp;

	while (ft_lstsize(*a) != 0)
	{
		temp = *a;
		dummy = (t_data *)temp->content;
		if (dummy->order <= vars->pivot)
			pb(a, b, vars);
		else if (dummy->order < (vars->pivot + vars->k))
		{
			pb(a, b, vars);
			if (ft_lstsize(*b) != 1)
				rb(b, vars);
		}
		else if ((vars->pivot + vars->k) <= dummy->order && ft_lstsize(*a) != 1)
		{
			rra(a, vars);
			vars->pivot--;
		}
		vars->pivot++;
	}
}

void	b_to_a(t_list **a, t_list **b, t_vars *vars)
{
	int		size;
	int		i;

	while (ft_lstsize(*b) != 0)
	{
		size = ft_lstsize(*b);
		if (size != 1)
		{
			i = get_biggest(b);
			if (i > size / 2)
			{
				while (i++ < size)
					rrb(b, vars);
			}
			else
			{
				while (i-- > 0)
					rb(b, vars);
			}
		}
		pa(a, b, vars);
	}
}

void	push_swap(t_list **a, t_list **b, t_vars *vars)
{
	if (vars->size <= 5)
		small_size(a, b, vars);
	else
	{
		a_to_b(a, b, vars);
		b_to_a(a, b, vars);
	}
}

void	push_swap2(t_list **a, t_list **b, t_vars *vars)
{
	if (vars->size <= 5)
		small_size(a, b, vars);
	else
	{
		a_to_b2(a, b, vars);
		b_to_a(a, b, vars);
	}
}
