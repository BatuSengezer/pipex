/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:06:33 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/27 15:39:18 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"
#include <sys/wait.h>
#include <fcntl.h>

void error_exit(void);
void execute(char *argv, char **envp);
char	*path_finder(char *cmd, char **envp);

#endif