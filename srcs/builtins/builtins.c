/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:06:21 by nick              #+#    #+#             */
/*   Updated: 2024/11/07 23:44:36 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	builtin_env(t_data *shell)
{
	t_env	*lst;
	
	lst = shell->env_lst;
	while(lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}

void	builtin_echo(char **argv, int n)
{
	// question for prince: how did you save the command line arguments that are filled in?
}

void	builtin_cd(t_data *shell)
{
	
}

void	builtin_pwd(t_data *shell)
{
	
}

void	builtin_unset(t_data *shell)
{
	
}

void	builtin_exit(t_data *shell)
{
	
}