/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:50:32 by pjang             #+#    #+#             */
/*   Updated: 2022/09/29 19:53:14 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*lst_new(void *content)
{
	t_data	*dummy;
	t_data	*data;
	t_list	*lst;

	dummy = (t_data *)content;
	lst = (t_list *)malloc(sizeof(t_list) * 1);
	data = (t_data *)malloc(sizeof(t_data) * 1);
	if (!lst)
		return (NULL);
	data->num = dummy->num;
	data->order = dummy->order;
	lst->content = (void *)data;
	lst->next = NULL;
	return (lst);
}
