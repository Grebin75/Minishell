/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:40:15 by grebin            #+#    #+#             */
/*   Updated: 2023/02/16 10:40:01 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/strings.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = -1;
	if (!s)
		return (0);
	while (s[++len])
		;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*scpy;
	int	i;
	int	len;

	len = ft_strlen(s1);
	scpy = malloc((len + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	i = -1;
	while (++i < len)
		scpy[i] = s1[i];
	scpy[i] = 0;
	return (scpy);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (n == 0)
		return (n);
	if (!*s1 || !*s2)
		return (0);
	i = -1;
	while (s1[++i] && s2[i] && s1[i] == s2[i] && i < n)
		;
	return ((unsigned char)*(s1 + i - (n == i)) - \
	(unsigned char)*(s2 + i - (n == i)));
}

int prints(char *str, char fd)
{
	int i;
	i = ft_strlen(str);
	write(fd, str, i);
	write(fd, "\n", 1);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s2_len = ft_strlen(s2);
	str = malloc((sizeof(char) * (s2_len + ft_strlen(s1) + 1)));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = 0;
	return (str);
}