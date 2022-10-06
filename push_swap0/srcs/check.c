/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 01:04:01 by pjang             #+#    #+#             */
/*   Updated: 2022/10/06 23:14:28 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	nullchar_check(char *str)
{
	if (ft_strncmp(str, "", 2) == 0)
		put_error();
}

void	check_char(int ac, char *av[])
{
	int	i;
	int	j;
	int	s_flag;

	i = 0;
	s_flag = 0;
	while (++i < ac)
	{
		nullchar_check(av[i]);
		j = -1;
		while (av[i][++j])
		{
			if ((!ft_isdigit(av[i][j])) && av[i][j] != ' ')
			{
				if (is_sign(av[i][j]) &&
					(!(j - s_flag == 1) || s_flag == 0))
					s_flag = j;
				else
					put_error();
			}
		}
		s_flag = 0;
	}
}

void	check_order(t_list *a)
{
	int		o_flag;
	t_data	*da;
	t_data	*dt;
	t_list	*temp;

	o_flag = 1;
	temp = a->next;
	while (temp)
	{
		da = (t_data *)a->content;
		dt = (t_data *)temp->content;
		if (da->order > dt->order)
			o_flag = 0;
		temp = temp->next;
		a = a->next;
	}
	if (o_flag)
		exit(1);
}
