/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:03:39 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/29 21:39:38 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wrong_input(void)
{
	ft_putstr_fd("Error: Invalid arguments..Correct arguments are:\n", 2);
	ft_putstr_fd("./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_FAILURE);
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		error_exit();
	return (file);
}

// Creates a pipe and fork. Child process receives input from the parent,
// redirects output to the write end of the pipe and executes the command.
// Parent process reads what was written to write end of the pipe by the child.
void	new_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_exit();
	pid = fork();
	if (pid == -1)
		error_exit();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

// Reads from the stdin and if line is not limiter, writes it to the
// write end of the pipe so that can parent process read it.
void	here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc < 6)
		wrong_input();
	if (pipe(fd) == -1)
		error_exit();
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		line = NULL;
		while (line != limiter)
		{
			line = get_next_line(0);
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && 
				ft_strlen(limiter) == ft_strlen(line) - 1)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
			fileout = open_file(argv[argc - 1], 1);
		}
		while (i < argc - 2)
			new_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	wrong_input();
}
