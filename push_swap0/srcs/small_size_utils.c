/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:46:52 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 05:30:56 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_el_2(t_list **a, int arr[], t_vars *vars)
{
	if (arr[0] == 1)
	{
		if (arr[1] == 0)
			sa(a, vars);
		else
			rra(a, vars);
	}
	if (arr[0] == 2)
	{
		if (arr[1] == 0)
			ra(a, vars);
		else
		{
			sa(a, vars);
			rra(a, vars);
		}
	}
}

void	three_el(t_list **a, int m_idx, t_vars *vars)
{
	int		i;
	int		arr[3];
	t_data	*td;
	t_list	*temp;

	temp = *a;
	i = -1;
	while (++i < 3)
	{
		td = (t_data *)temp->content;
		arr[i] = td->order - m_idx;
		temp = temp->next;
	}
	if (arr[0] == 0)
	{
		if (arr[1] == 2)
		{
			ra(a, vars);
			sa(a, vars);
			rra(a, vars);
		}
	}
	three_el_2(a, arr, vars);
}

void	four_el(t_list **a, t_list **b, t_vars *vars)
{
	int	i;

	i = get_biggest(a);
	if (i == 0)
		pb(a, b, vars);
	if (i == 1)
	{
		ra(a, vars);
		pb(a, b, vars);
	}
	if (i == 2)
	{
		ra(a, vars);
		ra(a, vars);
		pb(a, b, vars);
	}
	if (i == 3)
	{
		rra(a, vars);
		pb(a, b, vars);
	}
	three_el(a, 0, vars);
	pa(a, b, vars);
	ra(a, vars);
}
