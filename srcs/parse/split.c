/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:39:01 by gade-alm          #+#    #+#             */
/*   Updated: 2023/03/23 10:22:54 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_word(const char *s, int len)
{
	char			*word;
	int				i;

	i = -1;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		printerror("malloc error");
	while (s[++i] && i < len)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

int	count_args(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i] == '<' || str[i] == '<' || str[i] == '|')
			i = char_delim(str, i, "<>|");
		else if (str[i])
			i = char_delim(str, i, " \t<>|");
		else
			break ;
		count++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		i;
	char	**split;
	int		num_args;
	int		word_size;

	if (!str || !str[0])
		return (NULL);
	num_args = count_args(str);
	split = malloc(sizeof(char *) * (num_args + 1));
	if (!split)
		printerror("malloc error");
	i = -1;
	while (++i < num_args)
	{
		word_size = token_len(str);
		split[i] = malloc(sizeof(char) * (word_size + 1));
		if (!split[i])
			printerror("malloc error");
		split[i] = ft_word(str, word_size);
		str += word_size;
	}
	split[i] = NULL;
	return (split);
}
