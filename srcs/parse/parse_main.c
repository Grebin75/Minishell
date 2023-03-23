/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:38:11 by grebin            #+#    #+#             */
/*   Updated: 2023/03/23 12:46:54 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int check_red(char **arg, int i)
{
	while(arg[i])
	{
		if ((arg[i][0] == '>' || (arg[i][0] == '<' && arg[i][1] == '<') || arg[i][0] == '|' ))
			return (i);
		i++;
	}
	return (i);
}

int	cmd_split(char **arg, int i)
{
	int		j;
	int		index;
	char	**str;
	
	j = i;
	index = -1;
	i = check_red(arg, i);
	str = malloc(sizeof(char *) * ((i - j) + 1));
	if (!str)
		printerror("malloc error");
	while (j < i)
	{
		str[++index] = alloc_string(arg[j]);
		j++;
	}
	str[++index] = NULL;
	addtolast(&this()->cmds, createnode(str));
	this()->cmdsindex++;
	return (index);
}

int	redhandler(char **arg, int i)
{
	t_cmd *cmd;
	
	if (arg[i][0] == '\0')
		return (0);
	cmd = selectnode(this()->cmds, this()->cmdsindex - 1);
	//printlist(cmd);
	if (arg[i][0] == '<')
	{
		if (cmd->lasthere != 0)
				close(cmd->lasthere);
		cmd->input = heredocs(arg[i + 1]);
		cmd->lasthere = cmd->input;
	}
	if (arg[i][0] == '>' && ft_strlen(arg[i]) == 1)
	{
		if (cmd->output != 1)
				close (cmd->output);
			cmd->output = open(arg[i - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	}
	if (arg[i][0] == '>' && (ft_strlen(arg[i]) == 2 && arg[i][1] == '>'))
		cmd->output = open(arg[i - 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
	return (2 + (arg[i][0] == '>'));
}

void pipehandler(t_cmd *first, t_cmd *second)
{
	int fd[2];
	
	if (pipe(fd) == -1)
		printerror("Error creating a pipe");
	first->output = fd[1];
	second->input = fd[0];
}

void parse_main(char **arg)
{
	int	i;
	//char **arg = NULL;

	i = 0;
	// arg = função(str); depois do lexxer e expander.
	while (arg && arg[i])
	{
		i += cmd_split(arg, i);
		//printf("%s\n", arg[i]);
		if (arg[i] && (arg[i][0] == '>' || (arg[i][0] == '<' && ft_strlen(arg[i]) == 2)))
			i += redhandler(arg, i);
		if (arg[i] && arg[i][0] == '|')
		{
			i += cmd_split(arg, i);
			pipehandler(selectnode(this()->cmds, this()->cmdsindex - 2), selectnode(this()->cmds, this()->cmdsindex - 1));
		}
		//printf("%i\n%s\n", i, arg[i]);
	}
	//free(str);
}

