/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:00:29 by nick              #+#    #+#             */
/*   Updated: 2024/11/06 19:03:42 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//initiates start values of the shell struct
void	struct_init(t_data *shell)
{
	shell->exit = 0;
	return;
}

// opens files in read/write/append permissions based on a given int type
int	handle_file(char *filename, int type)
{
	int	fd;

	fd = 0;
	if (type == 0)
		fd = open(filename, O_RDONLY);
	else if (type == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == 2)
		fd = open(filename, O_WRONLY | O_CREAT |O_APPEND, 0644);
	else
		str_error("wrong type argument to handle file\n");
	if (fd == -1)
	{
		str_error("Cannot open file");
		exit(1);
	}
	return (fd);
}

//loops through t_env struct and frees all allocated memory
void	free_envlst(t_env *lst)
{
	t_env	*temp;
	
	temp = lst;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		if (temp->content)	
			free(temp->content);
		free(temp);
	}
}

// free the pipe_array from the last index that was allocated in memory
void	free_int_array(t_execution *pipex, int	i)
{
	int		**array;

	array = pipex->pipe_arr;
	if (!array)
		return;
	while (i >= 0)
	{
		if (array[i])
			free(array[i]);
		i--;
	}
	free(array);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
