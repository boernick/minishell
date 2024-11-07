/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:53:08 by nboer             #+#    #+#             */
/*   Updated: 2024/11/07 22:45:09 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	minishell(char **argv, int argc, t_data *shell, t_execution *pipex, char **env)
{
	(void) shell;
	
	pid_t		*pids;
	int			i;
	
	if (argc < 5)
		str_error("input error. Use: ./pipex file1 cmd1 cmd2 file2\n");
	else 
	{
		exec_init(pipex, argc, argv); // tellen hoeveel cmd args er zijn en het opslaan in struct
		create_pipes(pipex);
		pids = malloc(pipex->n_cmds * sizeof(pid_t));
		i = 0;
		while (pipex->index_cmd < pipex->n_cmds)
		{	
			pids[i] = fork_child();
			if (pids[i++] == 0) //case child
			{
				if (is_builtin(pipex))
				 	run_builtin(pipex);
				else
				{
					get_fd(pipex);
					clean_pipes(pipex);
					run_ex(argv[pipex->index_cmd + 2], env);
					exit(EXIT_SUCCESS);
				}
			}
			else
				update_exec(pipex);
		}
		ft_putstr_fd("parent waiting....\n", 2);
		clean_pipes(pipex);
		waitpids(pids, pipex->n_cmds); // wait for child process, but WHY these inputs in function?
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_execution	pipex;
	t_data		shell;
	
	struct_init(&shell); //function to initiate the struct and set some parameters
	t_env_init(&shell, envp);
	while (shell.exit == 0) //while no exit signal
	{
		//handle signals
		if (1) //TO-DO if input is correct
			minishell(argv, argc, &shell, &pipex, envp); //run minishell
	}
	//free t_env
	return (0);
}
