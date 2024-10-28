/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:17:53 by nboer             #+#    #+#             */
/*   Updated: 2024/10/28 23:10:44 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../includes/Libft/libft.h"

// if one single struct will be too messy or data is often irrelevant in parsing/exec we could separate between token struct and execution struct
typedef struct s_data
{
	pid_t		ex_pid; // process ID number, if 0 -> process = child
	int			ex_fdin; // FD in for pipe
	int			ex_fdout; // FD out for pipe
	int			ex_tag_out; // numbertag that indicates whether the outfile is read/write/append
	int			ex_p_exit; //expand latest exit status of the most recently executed foreground pipe. (case $?)
	char*		arg; // or cmd?
	char*		envp; //or char**?
}	t_data;

/* TOKENIZATION */

/* PARSE */

/* EXECUTE */
void	create_pipe(char *arg, char **path_env); // probrably t_data
int		handle_file(char *filename, int type);

/* BUILTINS */

/* ENV */
char	*get_path_env(char **path_env);
char	path_join(char *path_split, char *cmd_arg);

/* ERROR */
void	free_array(char **array);


#endif
