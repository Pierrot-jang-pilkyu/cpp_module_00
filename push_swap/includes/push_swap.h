/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:27:45 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 21:22:45 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MIN (-2147483648)
# define INT_MAX (2147483647)

typedef struct s_data
{
	int	num;
	int	order;
}				t_data;

typedef struct s_vars
{
	int		size;
	int		k;
	int		pivot;
	int		cmds;
	char	*print;
}				t_vars;

void		init_data(t_data *data);
void		init_vars(t_list *a, t_vars *vars);

void		put_error(void);

int			is_sign(char c);
int			is_integer(char *num);
void		check_order(t_list *a);
void		check_char(int ac, char *av[]);
long long	ft_atol(const char *str);
void		parsing(t_list **a, int ac, char *av[]);
void		put_reuslt(t_vars *vars);
void		print_re(t_vars *vars, const char *str);

// push_swap
int			get_biggest(t_list **list);
int			get_smallest(t_list **list);
void		three_el(t_list **a, int m_idx, t_vars *vars);
void		four_el(t_list **a, t_list **b, t_vars *vars);
void		small_size(t_list **a, t_list **b, t_vars *vars);
void		push_swap(t_list **a, t_list **b, t_vars *vars);
void		push_swap2(t_list **a, t_list **b, t_vars *vars);

t_list		*lst_new(void *content);

// command
void		sa(t_list **a, t_vars *vars);
void		sb(t_list **b, t_vars *vars);
void		ss(t_list **a, t_list **b, t_vars *vars);
void		pa(t_list **a, t_list **b, t_vars *vars);
void		pb(t_list **a, t_list **b, t_vars *vars);
void		ra(t_list **a, t_vars *vars);
void		rb(t_list **b, t_vars *vars);
void		rr(t_list **a, t_list **b, t_vars *vars);
void		rra(t_list **a, t_vars *vars);
void		rrb(t_list **b, t_vars *vars);
void		rrr(t_list **a, t_list **b, t_vars *vars);

#endif