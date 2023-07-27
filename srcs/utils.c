/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:49:41 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/27 14:40:09 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

// Checks for the path if path is found creates command array and executes the
// command otherwise exits.
void    execute(char *argv, char **envp)
{
    char **cmd;
    char *path;
    int i;

    i = 0;
    cmd = ft_split(argv, ' ');
    path = path_finder(cmd[0], envp);
    if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		error_exit();
	}
    if (execve(path, cmd, envp) == -1)
        error_exit();
}

// Finds the full path of a command by parsing and checking directories 
// provided by PATH environment variable. If command is found within 
// directories, returns the path, otherwise returns NULL.
char	*path_finder(char *cmd, char **envp)
{
    char **dir_paths;
    char *path;
    char *path_except_cmd;
    int i;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
    dir_paths = ft_split(envp[i] + 5, ':');
    i = 0;
    while (dir_paths[i])
    {
		path_except_cmd = ft_strjoin(dir_paths[i], "/");
		path = ft_strjoin(path_except_cmd, cmd);
		free(path_except_cmd);
		if (access(path, X_OK) == 0)
			return (path);
		else
		{
			free(path);
			i++;
		}
    }
    i = 0;
	while (dir_paths[i])
		free(dir_paths[i++]);
	free(dir_paths);
	return (NULL);
}