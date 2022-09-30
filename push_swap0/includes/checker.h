/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:41:33 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 22:27:33 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# define MAX_READ (1000000)

typedef struct s_cmds
{
	int		flen;
	int		size;
	char	*cmd_buf;
	char	**cmds;
}					t_cmds;

void	init_cmds(t_cmds *cmds);
void	get_cmds(t_cmds *cmds);
void	checker(t_cmds *cmds, t_list **a, t_list **b);

#endif