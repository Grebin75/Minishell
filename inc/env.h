/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:29:51 by grebin            #+#    #+#             */
/*   Updated: 2023/03/23 10:30:55 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "strings.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "allocation.h"
# include "struct.h"
# include "lists.h"
# include "minishell.h"

char	**create_env(char **env);
char	*check_var(char *line, char **env, int limit);
char	**add_var(char *line, char **env);
char	**rm_var(char *line, char **env, int limit);
char	**change_var(char *old, char *new, char **env, int limit);
int		find_path(t_cmd *cmd, char *path);
int		set_path(t_cmd *cmd);

#endif