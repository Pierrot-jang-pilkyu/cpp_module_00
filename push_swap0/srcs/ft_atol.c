/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:38:12 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 06:04:22 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(unsigned char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	val;

	sign = 1;
	result = 0;
	while (*str && ft_isspace((unsigned char)*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	val = 9223372036854775807;
	if (result > val && sign == 1)
		return (9223372036854775807);
	if (result > (val + 1) && sign == -1)
		return (-9223372036854775807);
	return ((result * sign));
}
