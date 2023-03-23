/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:12:13 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/23 10:21:54 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*expand_var(char *str, int i)
{
	char	*temp;
	int		j;

	j = 0;
	while (str[++i] && (str[i] != ' ' || str[i] != '\t'))
		j++;
	j--;
	temp = malloc(sizeof(char) * (j + 1));
	if (!temp)
		printerror("malloc error");
	temp = copy_var(str, i);
	j = -1;
	while (envs()->env[++j])
	{
		if (verify_var(temp, envs()->env[j], strcharlen(envs()->env[j], '=')))
			temp = print_env(str, envs()->env[j], i);
	}
	return (temp);
}

char	*print_env(char *str, char *env, int i)
{
	// char	*temp;

	(void)i;
	printf("STR %s\n", str);
	printf("env %s\n", env);
	return (str);
}
