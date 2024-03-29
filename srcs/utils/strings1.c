/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:39:06 by grebin            #+#    #+#             */
/*   Updated: 2023/03/16 17:03:20 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

long	ft_atoi(char *s)
{
	long	n;
	long	sig;
	int		i;

	n = 0;
	i = -1;
	sig = 1;
	while (s[++i] > 8 && s[i] < 13)
		;
	if (s[i] == '-' || s[i] == '+')
	{
		sig = (s[i] != '-') - (s[i] == '-');
		i++;
	}
	while (s[++i] >= '0' && s[i] <= '9')
		n = n * 10 + sig * (s[i++] - '0');
	while (s[i] > 8 && s[i] < 13)
		i++;
	return (n);
}
