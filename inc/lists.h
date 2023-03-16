/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:19:20 by hcoutinh          #+#    #+#             */
/*   Updated: 2023/03/16 08:46:01 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_cmd	t_cmd;
typedef struct s_red	t_red;

struct s_red
{
	int	fd;
	int	in;
	int	out;
	char *delim;
	t_red *next;
};

struct s_cmd
{
	int 	output;
	int 	input;
	int 	pid;
	int 	lasthere;
	char	*path;
	char	**cmd;
	t_red	*red;
	t_cmd	*next;
};

t_cmd	*createnode(char **cmd);
t_cmd	*addtolast(t_cmd **list, t_cmd *new);
t_cmd	*addtostart(t_cmd **list, t_cmd *new);
void	rmlist(t_cmd **list);
void	rmnode(t_cmd **list);

t_cmd	*selectnode(t_cmd *list, int n);
int		listsize(t_cmd *list);
t_cmd	*listcall(void);
void	printlist(t_cmd *list);
int lstindex(t_cmd *arg, t_cmd *list);


void rmred(t_red **red, int list);
t_red	*addred(t_red **list, t_red *new);
t_red *createred(int in, int out, int fd, char *delim);
#endif
