/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:54:09 by pjang             #+#    #+#             */
/*   Updated: 2022/10/07 01:43:39 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	get_cmds(t_cmds *cmds)
{
	cmds->cmds = ft_split(cmds->cmd_buf, '\n');
	cmds->size = get_strs(cmds->cmd_buf, '\n');
	free(cmds->cmd_buf);
	cmds->cmd_buf = NULL;
}
