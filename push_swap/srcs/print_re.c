/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_re.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 08:31:53 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 20:21:50 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_re(t_vars *vars, const char *str)
{
	char	*temp;

	temp = ft_strdup(vars->print);
	free(vars->print);
	vars->print = NULL;
	vars->print = ft_strjoin((const char *)temp, str);
	free(temp);
	temp = NULL;
}
