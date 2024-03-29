/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:53:03 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/30 14:38:45 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include "lists.h"
# include "allocation.h"
# include "builtins.h"
# include "struct.h"
# include "executor.h"
# include "env.h"
# include "struct.h"
# include "strings.h"

typedef struct s_args	t_args;
typedef struct s_env	t_env;

struct s_args{
	int		input;
	int		output;
	char	**cmd;
	char	*path;
	char	*next;
	char	*save_var;
};

struct s_env{
	char	**env;
};

//UTILS AREA
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		is_space(char str);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
int		printerror(char *str);

//STRINGS AREA
char	*ft_strdup(const char *s1);
int		prints(char *str, char fd);
char	*ft_strjoin(char const *s1, char const *s2);

//PARSE AREA
int		count_args(char *str);
int		char_delim(char *str, int i, char *delim);
char	*ft_word(const char *s, int len);
char	**ft_split(char *str);
int		check_single_quote(char *str, int i);
int		check_double_quote(char *str, int i);
int		check_string(char *str);
int		check_pipe(char *str, int i);
int		check_redirection(char *str, int i, char c);
int		token_helper(char *str, char c, int i);
int		token_len(char *str);
int		handle_commands(char *str);

void cmds_split(char **arg);

//EXPANDER AREA
t_env	*envs(void);
char	*expand_var(char *str, int i);
int		strcharlen(char *str, char c);
char	*print_env(char *str, char *env, int i);
char	*copy_var(char *str, int i);
int		ft_isalnum(int argument);
int		verify_var(char *str, char *env, int size);

#endif
