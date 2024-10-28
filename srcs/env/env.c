/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:20:22 by nick              #+#    #+#             */
/*   Updated: 2024/10/28 23:06:15 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Search through bin folder which dir contains PATH environment variable, 
// skips "PATH" in the string and returns it.
char *get_path_env(char **path_env)
{
	int i = 0;
	while (path_env[i])
	{
		if (ft_strnstr(path_env[i], "PATH", 4))
			return path_env[i] + 5; 
		i++;
	}
	return (NULL);
}

// join the trimmed path with the cmd argument to return the executable path.
char	*path_join(char *path_split, char *cmd_arg)
{
	char	*temp;
	char	*joined_path;

	temp = ft_strjoin(path_split, "/");
	joined_path = ft_strjoin(temp, cmd_arg);
	free(temp);
	return (joined_path);
}