/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:38:11 by grebin            #+#    #+#             */
/*   Updated: 2023/03/28 16:01:03 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	red_handler(int i, char *file, int ncmd)
{
	int fd;
	if (i == 1)
		selectnode(this()->cmds, ncmd)->input = open(file, O_RDONLY);
	if (i == 2)
		selectnode(this()->cmds, ncmd)->input = heredocs(file);
	if (i == 3)
		selectnode(this()->cmds, ncmd)->input = open(file, O_CREAT, O_TRUNC, 0644);
	if (i == 4)
		selectnode(this()->cmds, ncmd)->input = open(file, O_CREAT, O_APPEND, 0644);
}

char **fill_cmd(char **cmd, char *next)
{
	char **temp;
	int	i;

	i = -1;

	temp = alloc_matrix(cmd, 1);
	while (cmd[++i])
	{
		temp[i] = ft_strdup(cmd[i]);
		if (!temp)
		{
			free_matrix(temp);
			return (NULL); // EXIT PROG
		}
	}
	temp[i] == NULL;
	free_matrix(cmd);

	return (cmd);
}

int	set_cmd(char **arg, int i, int ncmd)
{
	int	i;
	char **cmd;

	i = 0;
	while (arg && arg[i] != '|')
	{
		if((arg[i] == '<' || arg[i] == '>') && ft_strlen(arg[i]) == 2)
			red_handler((arg[i] == '<') + (3 * (arg[i] == '>')) + ft_strlen(arg[i]) == 2, arg[i + 1], ncmd);
		else
			cmd = fill_cmd(cmd, arg[i]);
		i += (arg[i] == '<' || arg[i] == '>') + 1;
	}
	selectnode(this()->cmds, ncmd)->cmd = cmd;
	return (i);
}

void cmds_split(char **arg)
{
	int	i;
	int	ncmd;

	ncmd = 0;
	i = 0;
	while (arg && arg[i])
	{
		addtolast(&this()->cmds, createnode(NULL));
		i += set_cmd(arg, i, ncmd);
		ncmd++;
	}
	free_matrix(arg);
}
