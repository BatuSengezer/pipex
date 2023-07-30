/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:06:33 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/29 22:04:14 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>
# include <fcntl.h>

void	error_exit(void);
void	execute(char *argv, char **envp);
char	*path_finder(char *cmd, char **envp);
char	**cmd_with_single_quotes_parser(char *argv);
int		get_next_line_pipex(char **line);
int		open_file(char *argv, int i);
void	wrong_input(void);

#endif