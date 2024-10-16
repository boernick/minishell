/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:17:53 by nboer             #+#    #+#             */
/*   Updated: 2024/10/16 21:12:29 by nboer            ###   ########.fr       */
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
	
	char*		arg; // or cmd?
}	t_data;

/* TOKENIZATION */
char* function_xx();

/* PARSE */

/* EXECUTE */

/* BUILTINS */

/* ENV*/



#endif
