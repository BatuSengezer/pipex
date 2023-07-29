/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:49:41 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/29 15:35:30 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

// Checks for the path if path is found creates command array and executes the
// command otherwise exits.
void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	while (argv[i] != '\'' && argv[i])
		i++;
	if (argv[i] == '\'' && argv[ft_strlen(argv) - 1] == '\'')
		cmd = cmd_with_single_quotes_parser(argv);
	else
		cmd = ft_split(argv, ' ');
	i = 0;
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

char **cmd_with_single_quotes_parser(char *argv)
{
	char **ret;
	int i;

	ret = malloc(sizeof(char *) * 3);
	if (!ret)
		return (NULL);
	i = 0;
	while(argv[i] != ' ' && argv[i])
		i++;
	ret[0] = ft_substr(argv, 0, i);
	i += 2;
	ret[1] = ft_substr(argv, i, ft_strlen(argv) - i - 1);
	ret[2] = 0;
	return (ret);
}

// Finds the full path of a command by parsing and checking directories 
// provided by PATH environment variable. If command is found within 
// directories, returns the path, otherwise returns NULL.
char	*path_finder(char *cmd, char **envp)
{
	char	**dir_paths;
	char	*path;
	char	*path_except_cmd;
	int		i;

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
		free(path);
		i++;
	}
	i = 0;
	while (dir_paths[i])
		free(dir_paths[i++]);
	free(dir_paths);
	return (NULL);
}
