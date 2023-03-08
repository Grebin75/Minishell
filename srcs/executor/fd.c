/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:52:38 by grebin            #+#    #+#             */
/*   Updated: 2023/03/06 10:05:58 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int prep_fd(t_cmd *cmd)
{
	if (cmd->redirections[0] = Single)
		cmd->input = prep_input(cmd);
	else
		cmd->input = heredocs();
	if (cmd->redirections[1] = Single)
		cmd->output = open(cmd->cmd[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		cmd->output = open(cmd->cmd[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	
}

int prep_input()
{
	int fd;

	if ()
	return (fd);
}
int heredocs()
{
	
}