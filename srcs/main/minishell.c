/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:53:08 by nboer             #+#    #+#             */
/*   Updated: 2024/10/28 23:26:44 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	main(int argc, char *argv[], char **envp)
{
	t_data shell; //option is to declare one big struct that keeps track of all data.
	
	initstruct(&shell); //function to initiate the struct and set some parameters
	//init envp ??
	while (shell->exit == 1) //while no exit signal
	{
		//handle signals
		minishell(&shell) //run minishell
	}
	//free everything
	return (0)
}
