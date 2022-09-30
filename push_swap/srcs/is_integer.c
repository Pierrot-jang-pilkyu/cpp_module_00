/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:35:47 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 06:05:57 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_integer(char *num)
{
	if (!(ft_isdigit(*num) || is_sign(*num)))
		return (0);
	if (INT_MIN <= ft_atol(num) && ft_atol(num) <= INT_MAX)
		return (1);
	return (0);
}
