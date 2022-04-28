/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:03:39 by pjang             #+#    #+#             */
/*   Updated: 2022/04/28 17:23:23 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define MAX_READ 

/* get_next_line.c */

char		*get_next_line(int fd);
char		*division_str(char **str, int fd);
void		clear(int mode, char **str, char **buffer);
int			is_division(long long idx, char **s1, char **s2, char **s3);
void		refresh(long long mode, char **str, char **buffer, char *temp);

/* get_next_line_utils.c */

size_t		ft_strlen(const char *str);
long long	get_index(char *str);
char		*ft_strdup(const char *s1);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);

#endif
