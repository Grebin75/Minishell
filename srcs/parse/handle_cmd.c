/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:44:03 by gade-alm          #+#    #+#             */
/*   Updated: 2023/03/22 12:53:55 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	handle_commands(char *str)
{
	char	**split;
	int		i;
	int		j;

	i = -1;
	split = ft_split(str);
	if (!split)
		return (0);
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] == '\'')
				j = check_single_quote(str, j);
			if (split[i][j] == '$' && split[i][j])
				expand_var(split[i], j);
		}
	}
	return (1);
}
