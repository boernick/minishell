/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:43:56 by nboer             #+#    #+#             */
/*   Updated: 2024/10/28 21:08:39 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipe(char *arg, char **path_env)


// Search through the environment path folder until PATH dir is found. When found, format the path and run the executable
void	run_ex(char *arg, char **path_env) // TO-DO: ADD STRUCT
{
	int		i;
	char	**path_split;
	char	*check_path;
	char	**cmd_arg;

	i = 0;
	while (!(ft_strnstr(path_env[i], "PATH", 4)))
		i++;
	cmd_arg = ft_split(arg, ' ');
	path_split = ft_split(path_env[i] + 5, ':');
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