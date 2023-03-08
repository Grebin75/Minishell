/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:52:38 by grebin            #+#    #+#             */
/*   Updated: 2023/03/08 13:58:21 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int prep_fd(t_cmd *cmd)
{
	while (cmd->red)
	{
		if (cmd->red->in == 1)
			cmd->input = cmd->red->fd;
		if (cmd->red->in == 2)
			cmd->input = heredocs(cmd, cmd->red);
		if (cmd->red->out != 1)
			cmd->output = open(cmd->cmd[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (cmd->red->out != 2)
			cmd->output = open(cmd->cmd[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
		cmd->red = cmd->red->next;
	}
}

int heredocs()
{

}
