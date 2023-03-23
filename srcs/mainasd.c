/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/21 16:07:38 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int ac, char **av, char **envp)
{
	char			*str;
	static t_args	args;

	(void)ac;
	(void)av;
	(void)args;
	envs()->env = create_env(envp);
	while (1)
	{
		str = readline("$>>:");
		if (str && *str)
			add_history(str);
		
	}
	// addtolast(&this()->cmds, createnode(args.cmd));
	// echo(this()->cmds, 1);
	return (0);
}

/* int main(int ac, char **av, char **envp)
{
	char **str;

	this()->env = create_env(envp);
	while (1)
	{
		
		
	}	
	
}
 */