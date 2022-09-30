/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:05:06 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 04:10:16 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_biggest(t_list **list)
{
	int		i;
	t_data	max;
	t_data	*td;
	t_list	*temp;

	max.num = -1;
	max.order = 0;
	i = 0;
	temp = *list;
	while (temp)
	{
		td = (t_data *)temp->content;
		if (max.num < td->order)
		{
			max.num = td->order;
			max.order = i;
		}
		i++;
		temp = temp->next;
	}
	return (max.order);
}

int	get_smallest(t_list **list)
{
	int		i;
	t_data	min;
	t_data	*td;
	t_list	*temp;

	min.num = 99999999;
	min.order = 0;
	i = 0;
	temp = *list;
	while (temp)
	{
		td = (t_data *)temp->content;
		if (min.num > td->order)
		{
			min.num = td->order;
			min.order = i;
		}
		i++;
		temp = temp->next;
	}
	return (min.order);
}
