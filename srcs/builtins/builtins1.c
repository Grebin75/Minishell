/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:48:52 by grebin            #+#    #+#             */
/*   Updated: 2023/02/15 09:17:46 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

int export(t_cmd *cmd, char **env)
{
	int i;
	char *temp;


	i = -1;
	if (!cmd->cmd[1])
		return (1);
	temp = ft_strdup(cmd->cmd[1]);
	while (temp[++i] != '=' && temp[i])
		;
	if (!temp[i])
		return (0);
	if (check_var(temp, env, i))
		this()->env = change_var(temp, temp, env, i);
	else
		this()->env = add_var(temp, env);
	return (0);
}

void add_pwd()
{
	char *pwd;
	char *temp;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("pwd");
		return;
	}
	temp = ft_strjoin("PWD=", pwd);
	this()->env = add_var(temp, this()->env);
	free(pwd);
}

void change_pwd()
{
	char *old;
	char *temp;
	char *pwd;

	temp = ft_strdup(check_var("PWD=", this()->env, 3));
	old = ft_strjoin("OLD", temp);
	prints(old, 1);
	free(temp);
	if  (!check_var("OLDPWD=", this()->env, 7))
		this()->env = add_var(old, this()->env);
	else
		this()->env = change_var(check_var("OLDPWD=", this()->env, 7), old, this()->env, 7);
	temp  = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", temp);
	this()->env = change_var(check_var("PWD=", this()->env, 4), pwd, this()->env, 4);
	free(temp);
}

