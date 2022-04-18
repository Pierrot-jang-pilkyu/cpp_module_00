/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:38:32 by pjang             #+#    #+#             */
/*   Updated: 2022/04/18 13:38:35 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int				i;
	void			*result;
	unsigned char	*temp;

	i = count * size;
	result = malloc(i);
	if (!result)
		return (NULL);
	temp = result;
	while (i--)
	{
		temp[i] = 0;
	}
	return (result);
}
