/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:22:25 by grebin            #+#    #+#             */
/*   Updated: 2023/02/06 16:48:23 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/allocation.h"

char **alloc_matrix(char **matrix, int change)
{
	int i;
	char **new;

	i = -1;
	if (!matrix)
		return (NULL);
	while (matrix[++i])
		;
	new = malloc(sizeof(char *) * ((i + 1) + change));
	if (!new)
		return (NULL); // EXIT PROG
	return (new);
}

void free_matrix(char **matrix)
{
	int i;
	
	i = -1;
	if (!matrix)
		return;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

char *alloc_string(char *string)
{
	int i;
	int j;
	char *new;

	
	i = -1;
	j = -1;
	if (!string && !*string)
		return (NULL);
	while (string[++i])
		;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL); // EXIT PROG
	while (string[++j])
		new[j] = string[j];
	new[j] = 0;
	return (new);
}