/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:20:22 by nick              #+#    #+#             */
/*   Updated: 2024/10/30 00:28:06 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Takes an array of environment variables envp, creates a duplicate array,
//and returns a new dynamically allocated array of strings. 
// It frees allocated memory on failure and returns NULL.
t_env	t_env_init(char **envp)
{
	t_env	env_lst;
	
	int		i;

	env_lst.next = NULL;
	while (envp[i] != NULL)
	{
		// create new node
		// set next pointer to new node.
		// add envp[i] 
		i++;
	}

}
// Adds a new environment variable `value` to the `envp` array, resizing it. 
// `l` is the current length of `envp`. Return int to succes or failure. */
void	env_add(int l);

void	env_del();

//the linked list nodes need to be transformed into a continues string, but with each node
// seperated by a new line
void	env_getstr()

// Search through bin folder (NOW LINKED LIST) which dir contains PATH environment variable, 
// skips "PATH" in the string and returns it.
char *get_path_env(char **path_env)
{
	int i = 0;
	while (path_env[i]) // TO DO THIS WILL BECOME LINKED LIST
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