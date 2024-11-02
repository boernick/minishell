/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:53:08 by nboer             #+#    #+#             */
/*   Updated: 2024/11/02 17:09:49 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

// this was the main of PIPEX.. but needs to read the amount of tokens and based on that create an N amount of pipes.
void	minishell(char **argv, int argc, t_data *shell)
{
	int		i;
	int		file_out;
	int		file_in;
	char	**env;
		
	env = envlst_to_array(shell);
	i = 0;
	while (i < argc)
	{
		// if (ft_strncmp("here_doc", argv[1], 8) == 0) //if case redirect = true
		// {	
		// 	if (argc < 6) 
		// 		str_error("too little args"); //voor >> want: ./pipex here_doc LIMITER cmd cmd1 file zijn 6 args
		// 	i = 3;
		// 	file = handle_file(argv[argc - 1], 0);
		// 	//here_doc(argv, env);
		// }
		// else
		// {
			i = 2;
			file_in = handle_file(argv[1], 0);
			file_out = handle_file(argv[argc - 1], 1);
			dup2(file_in, STDIN_FILENO);
		// }
		while (i++ < argc - 2)
			create_pipe(argv[i + 2], env);
		dup2(file_out, STDOUT_FILENO);					//redirect STDOUT to file_out
		run_ex(argv[argc + 2], env);					//run last ex.
	}
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
