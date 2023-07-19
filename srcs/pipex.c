/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:03:24 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/15 22:08:37 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


void error_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int main (int ac, char **av)
{
	int fd[2];
	int pid;

	if (ac == 5)
	{
		if(pipe (fd) == -1)
			error_exit();
		pid = fork();
		if (pid == -1)
			error_exit();
		if (pid == 0)
			child_process(); // complete this function
		else
		{
		waitpid(pid, NULL, 0);
		parent_process(); // complete this function
		}
	}
	else
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		ft_putstr_fd("Correct arguments: ./pipex file1 cmd1 cmd2 file2\n", 1);
	}
	return (0);
}




// #include <errno.h>
// 	// test_main
// int main (int ac, char **av)
// {
// 	errno = EACCES;

// 	if (strcmp(av[1], "HELLO") == 0)
// 		printf ("%s", av[1]);
// 	else	
// 		error_exit();
// }