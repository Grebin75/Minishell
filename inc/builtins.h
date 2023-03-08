/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:07:54 by grebin            #+#    #+#             */
/*   Updated: 2023/03/08 12:06:07 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <readline/readline.h>
# include <readline/history.h>

# include "strings.h"
# include "env.h"
# include "allocation.h"
# include "struct.h"
# include "lists.h"

int	pwd(int output);
int env(t_cmd *cmd, char **env, int output);
int echo(t_cmd *cmd, int output);
int unset(t_cmd *cmd);
int export(t_cmd *cmd, char **env);
int cd(t_cmd *cmd, char **env);

void change_pwd();
int add_pwd();
int exit_prog(t_cmd *cmd, int status);

#endif
