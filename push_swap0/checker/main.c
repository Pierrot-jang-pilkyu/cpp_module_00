/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:32:16 by pjang             #+#    #+#             */
/*   Updated: 2022/09/30 22:28:48 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_cmds	cmds;
	t_list	*a;
	t_list	*b;

	if (argc != 1)
	{
		check_char(argc, argv);
		parsing(&a, argc, argv);
		check_order(a);
		init_cmds(&cmds);
		cmds.cmd_buf = (char *)malloc(sizeof(char) * MAX_READ);
		if (!cmds.cmd_buf)
			put_error();
		i = 0;
		cmds.flen = read(0, cmds.cmd_buf, sizeof(cmds.cmd_buf));
		while (cmds.flen != 0 && cmds.flen != -1 && cmds.flen < MAX_READ)
		{
			i += cmds.flen;
			cmds.flen = read(0, &cmds.cmd_buf[i], sizeof(cmds.cmd_buf));
		}
		get_cmds(&cmds);
		checker(&cmds, &a, &b);
	}
}