#include <stdio.h>
#include <stdlib.h>
#include "includes/minishell.h" // Adjust the path as necessary



size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*ft_strdup(const char *str)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (p != NULL)
	{
		while (i < len)
		{
			p[i] = str[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

// Free function to clean up the linked list
void	free_env_list(t_env *head)
{
	t_env	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
	}
}

// Print function to display the linked list contents
void	print_env_list(t_env *head)
{
	while (head)
	{
		printf("%s\n", head->content);
		head = head->next;
	}
}
int	t_env_init(t_data *shell, char **envp)
{
	t_env	*current;
	int		i;
	
	current = (t_env *)malloc(sizeof(t_env));
	if (!(shell->env_lst))
		return (-1); //TO DO HANDLE ERRORS //DO I NEED TO FREE?
	current->content = ft_strdup(envp[0]);
	current->next = NULL;
	shell->env_lst = current;
	i = 1;
	while (envp && envp[i])
	{
		current->next = (t_env *)malloc(sizeof(t_env));
		if (!(current->next))
			return (-1);
		current = current->next;
		current->content = ft_strdup(envp[i]);
		current->next = NULL;
		i++;
	}
	return (0);
}

int main(void)
{
	t_data shell;
	char *envp[] = {"USER=testuser", "HOME=/home/testuser", "PATH=/usr/bin", NULL};

	// Initialize the environment linked list
	if (t_env_init(&shell, envp) == -1)
	{
		fprintf(stderr, "Failed to initialize environment list.\n");
		return (1);
	}

	// Print the environment list to verify contents
	printf("Environment List:\n");
	print_env_list(shell.env_lst);

	// Free the linked list after use
	free_env_list(shell.env_lst);

	return (0);
}
