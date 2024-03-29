/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:59:59 by grebin            #+#    #+#             */
/*   Updated: 2023/04/04 18:22:37 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.h"

int	len(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i] && (str[i] != ':' && str[i] != 32))
		;
	return (i);
}

char	*fusion_path(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	k = -1;
	if (!s1 || !s2)
		return (NULL);
	//printf("s1: %s\n", s2);
	i += len(s1) + len(s2);
	s3 = malloc(sizeof(char) * (i + 2));
	if (!s3)
		printerror("malloc error");
	while (s1[++j] && j < len(s1))
		s3[++k] = s1[j];
	s3[++k] = '/';
	j = -1;
	while (s2[++j])
		s3[++k] = s2[j];
	s3[++k] = 0;
	return (s3);
}

int	find_path(t_cmd *cmd, char *path)
{
	char *temp;
	
	if (!path)
		return (1);
	path += 5;

	while (*path)
	{
		temp = fusion_path(path, cmd->cmd[0]);
		if (!temp)
			return (prints("command not found", 2));
		if (access(temp, F_OK) != -1)
		{
			cmd->path = temp;
			break ;
		}
		free(temp);
		path += len(path) + (path[len(path)] == ':');
	}
	if (!cmd->path)
		return (prints("Command not found.", 2));
	return (0);
}

int set_path(t_cmd *cmd)
{
	printf("entrou\n");
	if (cmd->path)
	{
		if (access(cmd->path, F_OK) == -1)
			return (1);
	}
	else
		find_path(this()->cmds, check_var("PATH=", this()->env, 5));
	return (0);
}