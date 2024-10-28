/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:43:56 by nboer             #+#    #+#             */
/*   Updated: 2024/10/28 22:05:42 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipe(char *arg, char **path_env) //TO-DO: ADD STRUCT
{
	int		fd[2];
	pid_t	pid;
	
	if (pipe(fd) == -1)
		str_error("pipe error");
	pid = fork();
	if (pid < 0)
		str_error("false PID");
	if (pid > 0) //parent process manages to read from the pipe (in which the result fom the previous command is stored)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
	if (pid == 0) // child process
	{
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		run_ex(arg, path_env);
	}
}

// Format the path and run the executable
void	run_ex(char *arg, char **path_env) // TO-DO: ADD STRUCT
{
	int		i;
	char	**path_split;
	char	*check_path;
	char	**cmd_arg;

	path_split = get_path_env(path_env);
	i = 0;
	while (path_split[i])
	{
		check_path = path_join(path_split[i], cmd_arg[0]);
		if (!(access(check_path, F_OK)))
			if (execve(check_path, cmd_arg, path_env) == -1)
				str_error("exec error");
		i++;
		free(check_path);
	}
	free_array(cmd_arg);
	free_array(path_split);
	str_error("cmd not found");
}