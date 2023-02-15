/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/02/15 09:21:15 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void testinit()
{
	char **str;
	char **stri;
	
	str = malloc(sizeof(char *) * (2 + 1));
	if (!str)
		return ;
	str[0] = alloc_string("export");
	str[1] = alloc_string("uadh=273673");
	str[2] = NULL;
	addtolast(&this()->cmds, createnode(str));
	
	stri = malloc(sizeof(char *) * (2 + 1));
	stri[0] = alloc_string("export");
	stri[1] = alloc_string("uadh=123");
	stri[2] = NULL;
	addtolast(&this()->cmds, createnode(stri));
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
	executor(this()->cmds);
	//executor(this()->cmds);
	//printlist(this()->cmds);
	rmlist(&this()->cmds);
	while (this()->env[++i])	
		prints(this()->env[i], 1);
	printf("Status: %d\n", this()->status);
	//env(this()->cmds, this()->env, 1);
	
	
	return (0);
}
