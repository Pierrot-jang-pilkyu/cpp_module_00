/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:33:21 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 06:07:28 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_fix(t_list **a, t_data *data)
{
	t_data	*dummy;
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		dummy = (t_data *)temp->content;
		if (dummy->num < data->num)
			data->order++;
		else if (dummy->num == data->num)
			put_error();
		else if (dummy->num > data->num)
			dummy->order++;
		temp = temp->next;
	}
}

void	in_list(t_list **a, char *num)
{
	t_data	data;

	init_data(&data);
	if (is_integer(num))
	{
		data.num = ft_atoi(num);
		order_fix(a, &data);
		ft_lstadd_back(a, lst_new((void *)&data));
	}
	else
		put_error();
}

int	get_strs(const char *s, char c)
{
	int	result;

	result = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != '\0')
			result++;
		while (*s && *s != c)
			s++;
	}
	return (result);
}

void	safety_free(char **split)
{
	int	len;

	len = 0;
	while (split[len] != NULL)
		len++;
	while (--len >= 0)
		free(split[len]);
	free(split);
}

void	parsing(t_list **a, int ac, char *av[])
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (++i < ac)
	{
		if (*av[i] == '\0')
			exit(1);
		split = ft_split(av[i], ' ');
		j = -1;
		while (++j < get_strs(av[i], ' '))
			in_list(a, split[j]);
		safety_free(split);
	}
}
