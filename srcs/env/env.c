/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:20:22 by nick              #+#    #+#             */
/*   Updated: 2024/11/01 16:06:59 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Takes an array of environment variables envp, creates a linked list,
//saves a copy of the env_array in SHELL->t_env and returns 0 when SUCCEED.
int	t_env_init(t_data *shell, char **envp)
{
	t_env	*current;
	int		i;
	
	current = (t_env *)malloc(sizeof(t_env));
	if (!(current))
		return (-1); //TO DO HANDLE ERRORS //DO I NEED TO FREE?
	current->content = ft_strdup(envp[0]);
	if (!(current->content))
		//free
		//return (-1)
	current->next = NULL;
	shell->env_lst = current;
	i = 1;
	while (envp && envp[i])
	{
		current->next = (t_env *)malloc(sizeof(t_env));
		if (!(current->next))
		{
			// free_lst(current);
			return (-1);
		}
		current = current->next;
		current->content = ft_strdup(envp[i]);
		// if !(current->content)
			//free_lst(current);
			//return (-1)
		current->next = NULL;
		i++;
	}
	return (0);
}
// Adds a new environment variable `value` to the `envp` list. 
// Return int to succes or failure. */
int	env_addback(t_data *shell, char *envp)
{
	t_env	*current;
	t_env	*new;
	
	current = shell->env_lst;
	while(current->next)
		current = current->next;
	new = (t_env *) malloc(sizeof(t_env));
	if (!(new))
		return (-1);
	new->content = ft_strdup(envp);
	if (!(new->content));
	{
		free(new);
		return (-1);
	}
	new->next = NULL;
	current->next = new;
	return (0);
}
// Deletes an environment variable from the list and
// relinks the remaining nodes.
int	env_del(t_data *shell, char *envp)
{
	t_env	*lst;
	t_env	*prev;
	int		l;

	lst = shell->env_lst;
	prev = NULL;
	l = ft_strlen(envp);
	while (lst) // for every node
	{
		if (!ft_strncmp(lst->content, envp, l) && lst->content[l] == '=')
		{
			if (prev)
				prev->next = lst->next;
			else // case head
				shell->env_lst = lst->next;	
			free(lst->content);
			free(lst);
			return (0);
		}
		prev = lst;
		lst = lst->next;
	}
	return (-1);
}
//the linked list nodes need to be transformed into a continues string, but with each node
// seperated by a new line
char	*env_getstr(t_data *shell)
{
	t_env	*lst;
	char	*str;

	str = NULL;
	lst = shell->env_lst;
	while (lst)
	{
		if (!(str = ft_strjoin(str, lst->content)))
		{
			free(str);
			return (NULL);
		}
		if (lst->next)
		{
			if (!(str = ft_strjoin(str, "\n")))
			{
				free(str);
				return (NULL);
			}
		}
		lst = lst->next;
	}
	return (str);
}


// Search through bin folder (NOW LINKED LIST) which dir contains PATH environment variable, 
// skips "PATH" in the string and returns it.
char	*get_path_env(char **path_env)
{
	int i = 0;
	while (path_env[i]) // TO DO THIS WILL BECOME LINKED LIST
	{
		if (ft_strnstr(path_env[i], "PATH", 4))
			return (path_env[i] + 5); 
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
	if (!temp)

	joined_path = ft_strjoin(temp, cmd_arg);
	free(temp);
	return (joined_path);
}
