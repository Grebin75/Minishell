/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:28:40 by grebin            #+#    #+#             */
/*   Updated: 2023/03/08 13:23:07 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.h"


char *check_var(char *line, char **env, int limit)
{
	int i;

	i = -1;
	while (env[++i])
		if (ft_strncmp(env[i], line, limit) == 0)
			return (env[i]);
	return (NULL);
}

char	**change_var(char *old, char *new, char **env, int limit)
{
	int i;
	char *temp;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(old, env[i], limit) == 0)
		{
			temp = env[i];
			free (temp);
			env[i] = alloc_string(new);
			return (env);
		}
	}
	return (env);
}

char **add_var(char *line, char **env)
{
	int i;
	char **temp;

	temp = env;
	env = alloc_matrix(env, 1);
	i = -1;
	//ADD CHECK DE DUPE
	while (temp[++i])
	{
		env[i] = ft_strdup(temp[i]);
		if (!env[i])
		{
			free(env);
			return (NULL);
		}
	}
	env[i] = line;
	env[++i] = NULL;
	free_matrix(temp);
	return(env);
}
char **rm_var(char *line, char **env, int limit)
{
	int i;
	int j;
	char **temp;

	j = -1;
	temp = env;
	env = alloc_matrix(env, -1);
	if (!env)
		return (NULL);
	i = -1;
	while (temp[++i])
	{
		if (ft_strncmp(line, temp[i], limit))
			env[++j] = ft_strdup(temp[i]);
		if (!env[j])
		{
			free(env);
			return (NULL);
		}
	}
	env[j] = NULL;
	free_matrix(temp);
	return (env);
}

char **create_env(char **env)
{
	char **new;
	int i;

	new = alloc_matrix(env, 0);
	i = -1;
	while (env[++i])
	{
		new[i] = ft_strdup(env[i]);
		if (!new)
		{
			free(new);
			return (NULL);
		}
	}
	new[i] = NULL;
	return (new);
}
