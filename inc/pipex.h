/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:42:25 by vbartos           #+#    #+#             */
/*   Updated: 2023/08/29 10:55:28 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

void	ft_pipex_init(int *fd, int child1, char **argv, char **envp);
void	ft_pipex_close(int *fd, int child2, char **argv, char **envp);
void	ft_run_cmd(char *argv, char **envp);
char	*ft_parse_path(char *cmd, char **envp);
char	*ft_extract_path(char **envp);
void	ft_free_list(char **list);
int		ft_arg_check(int argc, char **argv);

#endif