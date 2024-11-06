/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:11:28 by nboer             #+#    #+#             */
/*   Updated: 2024/11/07 00:35:16 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks if a given cmd argument is a builtin function
int	is_builtin(t_execution *pipex, char **argv)
{
	(void) pipex;
	if (!(ft_strncmp(argv[1], "echo", 4)))
	{
		if (!(ft_strncmp(argv[2], "-n", 2)))
			return (2);
		return (1);
	} 
	if (!ft_strncmp(argv[1], "cd", 2))
		return (3);
	if (!ft_strncmp(argv[1], "pwd", 3))
		return (4);
	if (!ft_strncmp(argv[1], "unset", 5))
		return (5);
	return (-1);
}

// runs a given builtin function
int	run_builtin(char* arg)
{
	return (0);
}
