/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:22:25 by grebin            #+#    #+#             */
/*   Updated: 2023/03/30 15:12:57 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
//EXIT PROG ON RETURN NULL
char	**alloc_matrix(char **matrix, int change)
{
	int		i;
	char	**new;

	i = -1;
	if (!matrix)
	{
		if (change >= 1)
		{
			new = malloc(sizeof(char *) * (1 + change));
			if (!new)
				printerror("malloc error");
		}
		else
			new = NULL;
		return (new);
	}
	while (matrix[++i])
		;
	new = malloc(sizeof(char *) * ((i + 1) + change));
	if (!new)
		printerror("malloc error");
	return (new);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

//EXIT PROG ON RETURN NULL
char	*alloc_string(char *string)
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
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		printerror("malloc error");
	while (string[++j])
		new[j] = string[j];
	new[j] = 0;
	return (new);
}
