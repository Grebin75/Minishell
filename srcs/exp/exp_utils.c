/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:13:38 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/23 10:21:48 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (-1);
	if (!*s1 || !*s2)
		return (-1);
	while ((s1[a] != 0) && (s2 != 0) && (s1[a] == s2[a]) && (a < n - 1))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

char	*copy_var(char *str, int i)
{
	int		size;
	char	*temp;

	size = 0;
	while (str[--i] && str[i] != '$')
		size++;
	size--;
	i++;
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		printerror("malloc error");
	size = 0;
	while (str[i])
	{
		temp[size] = str[i];
		i++;
		size++;
	}
	temp[size] = '\0';
	return (temp);
}

int	strcharlen(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] != c)
		;
	i--;
	return (i);
}

t_env	*envs(void)
{
	static t_env	envs;

	return (&envs);
}

int	verify_var(char *str, char *env, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == env[i])
			i++;
		else
			return (0);
	}
	if ((!str[i + 1] && size == i))
		return (1);
	return (0);
}