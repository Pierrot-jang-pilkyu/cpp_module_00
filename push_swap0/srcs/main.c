/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:03 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 14:08:16 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_data(void *content)
{
	t_data	*d;

	d = (t_data *)content;
	ft_printf("%d ", d->num);
}

void	print_order(void *content)
{
	t_data	*d;

	d = (t_data *)content;
	ft_printf("%d ", d->order);
}

void	list_copy(t_list **dst, t_list **src)
{
	t_list	*ts;

	ts = *src;
	while (ts)
	{
		ft_lstadd_back(dst, lst_new(ts->content));
		ts = ts->next;
	}
}

int	main(int argc, char *argv[])
{
	t_vars	v[2];
	t_list	*a;
	t_list	*ac;
	t_list	*b;

	if (argc != 1)
	{
		check_char(argc, argv);
		parsing(&a, argc, argv);
		check_order(a);
		list_copy(&ac, &a);
		init_vars(a, &v[0]);
		push_swap(&a, &b, &v[0]);
		init_vars(ac, &v[1]);
		push_swap2(&ac, &b, &v[1]);
		ft_printf("\n\nstr : %s\n", v[0].print);
		ft_printf("\n\nstr : %s\n", v[1].print);
		if (v[0].cmds < v[1].cmds)
			put_reuslt(&v[0]);
		else
			put_reuslt(&v[1]);
	}
	return (0);
}

		// ft_lstiter(a, print_data);
		// ft_printf("\n");
		// ft_printf("\n\na : ");
		// ft_lstiter(a, print_order);
		// ft_printf("\n");