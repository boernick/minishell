/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:53:08 by nboer             #+#    #+#             */
/*   Updated: 2024/10/28 23:05:59 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	main(int argc, char *argv[], char **envp)
{
	t_data shell; //option is to declare one big struct that keeps track of all data.
	initstruct(&shell) //function to initiate the struct and set some parameters
	//init envp ??
	while (MINISHELL SHOULD NOT EXIT)
	{
		//handle signals
		minishell(&shell) // 
	}
	//free everything
	return (0)
}
