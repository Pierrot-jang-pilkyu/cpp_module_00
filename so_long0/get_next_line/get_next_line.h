/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:03:39 by pjang             #+#    #+#             */
/*   Updated: 2022/09/21 06:04:34 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define OPEN_MAX (10240)

/* get_next_line.c */

char		*get_next_line(int fd);
void		division_str(char **str, int fd);
void		clear(int mode, char **str, char **buffer);
void		refresh(long long mode, char **str, char **buffer, char *temp);

/* get_next_line_utils.c */

long long	get_index(char *str);

#endif
