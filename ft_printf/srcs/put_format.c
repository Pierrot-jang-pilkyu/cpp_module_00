/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:50:27 by pjang             #+#    #+#             */
/*   Updated: 2022/05/31 03:22:44 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	put_format(const char *format, size_t *result, size_t *idx, va_list *ap)
{
	if (is_conversion(format[*idx]))
	{
		put_nonflag(format[*idx], ap, result);
		*idx += 1;
	}
}
