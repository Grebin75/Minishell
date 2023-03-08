/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/06 10:02:12 by grebin           ###   ########.fr       */
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
	str[0] = alloc_string("ls");
	str[1] = alloc_string("-l");
	str[2] = NULL;
	addtolast(&this()->cmds, createnode(str));
	stri = malloc(sizeof(char *) * (2));
	stri[0] = alloc_string("ls");
	stri[1] = NULL;
	//stri[2] = NULL;
	addtolast(&this()->cmds, createnode(stri));
	//printlist((t_list *)this()->cmds->next);
}


int	main(int ac, char **av, char **ev)
{
	//char *line = NULL;
	int i = -1;
	int input = dup(STDIN_FILENO);
	int output = dup(STDOUT_FILENO);

	(void)ac;
	(void)av;
	(void)ev;
	(void)i;
	
	testinit();

	this()->env = create_env(ev);
	//this()->env = change_var("PATH=", "PATH=12323", this()->env, ft_strlen("PATH="));
	//unset(this()->cmds);
	//cd(this()->cmds->next, this()->env);
	//executor(this()->cmds);
	//this()->cmds->output = open("output", O_WRONLY);
	set_path(this()->cmds);
	executor(this()->cmds);
	dup2(input, STDERR_FILENO);
	dup2(output, STDOUT_FILENO);
	printf("%i\n", STDIN_FILENO);
	set_path(this()->cmds);
	executor(this()->cmds);
	//printf("%s\n", this()->cmds);
	//printlist(this()->cmds);
	/* while (this()->env[++i])	
		prints(this()->env[i], 1); */
	//printf("Status: %d\n", this()->status);
	//env(this()->cmds, this()->env, 1);
	rmlist(&this()->cmds);
	
	
	return (0);
}

/* int main()
{
	int input;
	int output;
	
	input = dup(STDIN_FILENO);
	output = dup(STDOUT_FILENO);
	this()->env = create_env(ev);
	while (1)
	{
		get_arg();
		executor(this()->cmds);
		dup2(input, STDERR_FILENO);
		dup2(output, STDOUT_FILENO);
	}
} */