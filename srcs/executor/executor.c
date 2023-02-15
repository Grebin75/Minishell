/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:20:18 by grebin            #+#    #+#             */
/*   Updated: 2023/02/15 09:19:24 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void executor(t_cmd *cmd)
{
	if (ft_strncmp("cd", cmd->cmd[0], 3) == 0 || ft_strncmp("echo", \
	cmd->cmd[0], 5) == 0 || ft_strncmp("exit", cmd->cmd[0], 5) == 0 \
	|| ft_strncmp("unset", cmd->cmd[0], 6) == 0 || ft_strncmp("pwd", \
	cmd->cmd[0], 4) == 0 || ft_strncmp("export", cmd->cmd[0], 7) == 0 \
	|| ft_strncmp("env", cmd->cmd[0], 4) == 0)
		builtins(cmd);
	
	/* else
		cmd_handler(this()->env, cmd->input, cmd->output); */
}

void builtins(t_cmd *cmd)
{
	if (ft_strncmp("cd", cmd->cmd[0], 3) == 0)
		this()->status = cd(cmd, this()->env);
	if (ft_strncmp("echo", cmd->cmd[0], 5) == 0)
		this()->status = echo(cmd, cmd->output);
	if (ft_strncmp("unset", cmd->cmd[0], 6) == 0)
		this()->status = unset(cmd);
	if (ft_strncmp("export", cmd->cmd[0], 7) == 0)
		this()->status = export(cmd, this()->env);
	if (ft_strncmp("env", cmd->cmd[0], 4) == 0)
		this()->status = env(cmd, this()->env, cmd->output);
	if (ft_strncmp("pwd", cmd->cmd[0], 4) == 0)
		this()->status = pwd(cmd->output);
/* 	if (ft_strncmp("exit", cmd->cmd[0], 3) == 0)
		exit(cmd, this()->status); */
	rmnode(&this()->cmds);
}