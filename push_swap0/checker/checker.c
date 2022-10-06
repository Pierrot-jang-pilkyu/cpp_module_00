/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:41:01 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 22:32:36 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_cmd(char *cmd, t_list **a, t_list **b)
{
	t_vars	vars;

	init_vars(*a, &vars);
	if (ft_strncmp(cmd, "sa", 2) == 0)
		sa(a, &vars);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		sb(b, &vars);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		ss(a, b, &vars);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		pa(a, b, &vars);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		pb(a, b, &vars);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		ra(a, &vars);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		rb(b, &vars);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		rr(a, b, &vars);
	else if (ft_strncmp(cmd, "rra", 2) == 0)
		rra(a, &vars);
	else if (ft_strncmp(cmd, "rrb", 2) == 0)
		rrb(b, &vars);
	else if (ft_strncmp(cmd, "rrr", 2) == 0)
		rrr(a, b, &vars);
}

int	check_order2(t_list *a)
{
	t_data	*da;
	t_data	*dt;
	t_list	*temp;

	temp = a->next;
	while (temp)
	{
		da = (t_data *)a->content;
		dt = (t_data *)temp->content;
		if (da->order > dt->order)
			return (0);
		temp = temp->next;
		a = a->next;
	}
	return (1);
}

void	checker(t_cmds *cmds, t_list **a, t_list **b)
{
	int	i;

	i = -1;
	while (++i < cmds->size)
		check_cmd(cmds->cmds[i], a, b);
	if (check_order2(*a))
	{
		if (!*b)
			ft_printf("OK\n");
	}
	ft_printf("KO\n");
}