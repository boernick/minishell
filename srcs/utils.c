/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:00:29 by nick              #+#    #+#             */
/*   Updated: 2024/11/02 17:10:28 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	struct_init(t_data *shell)
{
	shell->arg = "cat";
	shell->exit = 0;
}

int	handle_file(char *filename, int type)
{
	int	fd;

	if (type = 0)
		fd = open(filename, O_RDONLY | 0777);
	if (type == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (type = 2)
		fd = open(filename, O_WRONLY | O_CREAT |O_APPEND, 0777);
	else
		str_error("wrong type argument to handle file");
	return (fd);
}

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
