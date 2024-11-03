/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:53:08 by nboer             #+#    #+#             */
/*   Updated: 2024/11/03 13:45:21 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	minishell(char **argv, int argc, t_data *shell)
{
	..
}

int	main(int argc, char *argv[], char **envp)
{
	t_data shell;
	
	struct_init(&shell); //function to initiate the struct and set some parameters
	t_env_init(&shell, envp);
	while (shell.exit == 0) //while no exit signal
	{
		//handle signals
		if (1) //TO-DO if input is correct
			minishell(argv, argc, &shell); //run minishell
	}
	//free t_env
	return (0);
}
