/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:40:54 by pjang             #+#    #+#             */
/*   Updated: 2022/05/31 02:22:22 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_conversion_index(const char *format, size_t *idx)
{
	while (format[*idx])
	{
		if (format[*idx] == '%')
		{
			*idx += 1;
			break ;
		}
		*idx += 1;
	}
}
