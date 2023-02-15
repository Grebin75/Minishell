/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:13:43 by hcoutinh          #+#    #+#             */
/*   Updated: 2023/02/06 20:31:05 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lists.h"

// Return the amount of objects.
int	listsize(t_cmd *list)
{
	int		i;

	i = 0;
	if (!list)
		return (i);
	while (list->next && ++i)
		list = list->next;
	return (++i);
}

// Return obj on n position, return *list if n object dont exist.
t_cmd	*selectnode(t_cmd *list, int n)
{
	t_cmd	*temp;

	temp = list;
	if (n < 0 && !temp)
		return (NULL);
	while (temp && n--)
		temp = temp->next;
	return (temp);
}

void	printlist(t_cmd *list)
{
	int	i;
	int j;

	j = 0;
	while (list)
	{
		printf("LIST Nº%i\n", j);
		printf("PATH: %s\n", list->path);
		i = -1;
		while (list->cmd[++i])
			printf("CMD[%i]: %s\n", i, list->cmd[i]);
		j++;
		list = list->next;
	}
}

// Return list address

t_cmd	*listcall(void)
{
	static t_cmd	list;

	return (&list);
}
