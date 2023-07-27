/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:03:24 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/27 15:54:09 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Child process that duplicates the write end of the pipe to STDOUT fd,
// redirecting any output to STDOUT making it available for parent process.
// It also duplicates read end of the pipe to STDIN fd, redirecting input of
// the child process to make sure it is received from infile(argv[1]).
// Then executes the command(argv[2]).
void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error_exit();
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	execute(argv[2], envp);
}

// Parent process that duplicates the read end of the pipe to STDIN fd,
// redirecting any input from STDIN to make sure it is taken from the
// read end of the pipe which is written by the child process.
// It also duplicates fd of the outfile(argv[4]) to STDOUT fd, redirecting 
// output of the parent process to make sure it is written to the output file.
// Then executes the command(argv[3]).
void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error_exit();
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_exit();
		pid = fork();
		if (pid == -1)
			error_exit();
		if (pid == 0)
			child_process(argv, envp, fd);
		else
		{
			waitpid(pid, NULL, 0);
			parent_process(argv, envp, fd);
		}
	}
	else
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		ft_putstr_fd("Correct arguments: ./pipex file1 cmd1 cmd2 file2\n", 1);
	}
	return (0);
}
