/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:53:08 by nboer             #+#    #+#             */
/*   Updated: 2024/10/30 21:46:49 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


int	main(int argc, char *argv[], char **envp)
{
	t_data shell; //option is to declare one big struct that keeps track of all data.
	
	struct_init(&shell); //function to initiate the struct and set some parameters
	env_init(&shell, envp);
	while (shell.exit == 0) //while no exit signal
	{
		//handle signals
		if (1) //TO-DO if input is correct
			minishell(&shell); //run minishell
	}
	//free envp
	return (0);
}
