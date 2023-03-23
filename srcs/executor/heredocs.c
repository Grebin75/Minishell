/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:52:38 by grebin            #+#    #+#             */
/*   Updated: 2023/03/23 16:55:26 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"


int prep_heredocs(char *arg)
{
	int fd[2];
	int n = 0;

	if (pipe(fd) == -1)
		return (-1);
	n = ft_strlen(arg);
	printf("%s", arg);
	write(fd[1], arg, n);
	return (fd[0]);
}

char *rm_null(char *string)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = -1;
	if (!string && !*string)
		return (NULL);
	while (string[++i])
		;
	//printf("%s", string);
	new = malloc(sizeof(char) * i);
	if (!new)
		printerror("malloc error");
	while (string[++j])
		new[j] = string[j];
	//free(string);
	return (new);
}

int heredocs(char *delim)
{
	char *temp;
	char *temp1;
	char *arg;
	
	temp = NULL;
	arg = NULL;
	while (ft_strncmp(temp, delim, ft_strlen(temp)) != 0)
	{
		free(temp);
		temp = readline("<<: ");
		temp1 = ft_strjoin(temp, "\n");
		arg = ft_strjoin(arg, temp1);
		free(temp1);
	}
	return (prep_heredocs(arg));
}