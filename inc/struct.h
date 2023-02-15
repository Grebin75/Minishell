/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:17:00 by grebin            #+#    #+#             */
/*   Updated: 2023/02/06 20:33:51 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "lists.h"

typedef struct s_shell t_shell;

struct s_shell{
	char **env;
	int status;
	t_cmd *cmds;
};

t_shell *this();
#endif