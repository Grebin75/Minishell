/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:43:15 by grebin            #+#    #+#             */
/*   Updated: 2023/02/06 19:25:04 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, int n);
void 	prints(char *str, char fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif