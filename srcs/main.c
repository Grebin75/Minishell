/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/01 15:12:47 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void testinit()
{
	char **str;
	//char **stri;
	
	str = malloc(sizeof(char *) * (2 + 1));
	if (!str)
		return ;
	str[0] = alloc_string("ls");
	str[1] = alloc_string("-l");
	str[2] = NULL;
	addtolast(&this()->cmds, createnode(str));
	/* stri = malloc(sizeof(char *) * (2 + 1));
	stri[0] = alloc_string("export");
	stri[1] = alloc_string("uadh=123");
	stri[2] = NULL;
	addtolast(&this()->cmds, createnode(stri)); */
	//printlist((t_list *)this()->cmds->next);
}


int	main(int ac, char **av, char **ev)
{
	//char *line = NULL;
	int i = -1;

	(void)ac;
	(void)av;
	(void)ev;
	(void)i;
	
	testinit();

	this()->env = create_env(ev);
	//this()->env = change_var("PATH=", "PATH=12323", this()->env, ft_strlen("PATH="));
	//unset(this()->cmds);
	//cd(this()->cmds->next, this()->env);
	//export(this()->cmds->next, this()->env);
	//executor(this()->cmds);
	set_path(this()->cmds);
	executor(this()->cmds);
	//printf("%s\n", this()->cmds->cmd[0]);
	//printlist(this()->cmds);
	/* while (this()->env[++i])	
		prints(this()->env[i], 1); */
	//printf("Status: %d\n", this()->status);
	//env(this()->cmds, this()->env, 1);
	rmlist(&this()->cmds);
	
	
	return (0);
}
