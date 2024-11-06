/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:11:28 by nboer             #+#    #+#             */
/*   Updated: 2024/11/07 00:17:52 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks if a given cmd argument is a builtin function
int	is_builtin(t_execution *pipex, char **argv)
{
	(void) pipex;
	if (!(ft_strncmp(argv[1], "echo", 4)))
	{
		if (!(ft_strncmp(argv[2], "n", 4)))
			return (2);
		return (1);
	} 
	if (!())
	return (0);
}

// runs a given builtin function
int	run_builtin(char* arg)
{
	(void) pipex;
	return (0);
}
