/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:17:53 by nboer             #+#    #+#             */
/*   Updated: 2024/10/28 20:58:20 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../includes/Libft/libft.h"

typedef struct s_data
{
	pid_t		pid; // process ID number, if 0 -> process = child
	int			fd_in; // FD in for pipe
	int			fd_out; // FD out for pipe
	int			tag_out; // numbertag that indicates whether the outfile is read/write/append
	int			p_exit; //expand latest exit status of the most recently executed foreground pipe. (case $?)
	char*		arg; // or cmd?
}	t_data;

/* TOKENIZATION */
char* function_xx();

/* PARSE */

/* EXECUTE */
void	create_pipe(char *arg, char **path_env);


/* BUILTINS */

/* ENV*/



#endif
