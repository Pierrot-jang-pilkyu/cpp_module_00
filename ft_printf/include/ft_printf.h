/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:09:34 by pjang             #+#    #+#             */
/*   Updated: 2022/09/19 22:01:41 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"
# define DECIMAL "0123456789"
# define HEXA_DECIMAL_UP "0123456789ABCDEF"
# define HEXA_DECIMAL_LOW "0123456789abcdef"

typedef struct s_flag
{
	int	result;
	int	sharp_flag;
	int	minus_flag;
	int	plus_flag;
	int	space_flag;
	int	zero_flag;
	int	width_flag;
	int	dot_flag;
}				t_flag;

int		ft_printf(const char *format, ...);
void	get_conversion_index(const char *format, size_t *idx);
void	put_format(const char *format, size_t *result, \
	size_t *idx, va_list *ap);
int		is_conversion(char c);
void	put_nonflag(char c, va_list *ap, size_t *result);

// print

void	print_char(char c, size_t *result);
void	print_str(char *str, size_t *result);
void	print_nbr_base(long long nbr, char *base, size_t *result);
void	print_ptr(unsigned long ptr, size_t *result);

#endif
