/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 08:53:46 by vbartos           #+#    #+#             */
/*   Updated: 2023/08/29 10:57:20 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

//find executable path for cmd, format it for use in execve
char	*ft_parse_path(char *cmd, char **envp)
{
	int		i;
	char	*extracted_path;
	char	**path_list;
	char	*temp;
	char	*working_path;

	extracted_path = ft_extract_path(envp);
	path_list = ft_split(extracted_path, ':');
	i = 0;
	while (path_list[i] != NULL)
	{
		temp = ft_strjoin(path_list[i], "/");
		working_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(working_path, F_OK) == 0)
		{
			ft_free_list(path_list);
			return (working_path);
		}
		free(working_path);
		i++;
	}
	ft_free_list(path_list);
	perror("Cannot locate executable");
	exit(EXIT_FAILURE);
}

//parse path for provided cmd, run execve
void	ft_run_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = ft_parse_path(cmd[0], envp);
	execve(path, cmd, envp);
	ft_free_list(cmd);
	free(path);
	perror("Did not execute cmd");
	exit(EXIT_FAILURE);
}

//open infile, open pipe, fork child1, execve first cmd on infile inside child1
void	ft_pipex_init(int *fd, int child1, char **argv, char **envp)
{
	int	infile;

	if (pipe(fd) == -1)
		perror("Error opening pipe");
	child1 = fork();
	if (child1 == -1)
		perror("Error forking child process 1");
	if (child1 == 0)
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			perror("Infile cannot be opened");
		close(fd[0]);
		if (dup2(infile, STDIN_FILENO) == -1)
			perror("Error duplicating file descriptor in child 1");
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			perror("Error duplicating file descriptor in child 1");
		close(fd[1]);
		close(infile);
		ft_run_cmd(argv[2], envp);
	}
}

//open outfile, fork child2, execve second cmd on
//content stored in pipe, write result to outfile
void	ft_pipex_close(int *fd, int child2, char **argv, char **envp)
{
	int	outfile;

	child2 = fork();
	if (child2 == -1)
		perror("Error forking child process 2");
	if (child2 == 0)
	{
		outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (outfile == -1)
			perror("Outfile cannot be opened");
		close(fd[1]);
		if (dup2(outfile, STDOUT_FILENO) == -1)
			perror("Error duplicating file descriptor in child 2");
		if (dup2(fd[0], STDIN_FILENO) == -1)
			perror("Error duplicating file descriptor in child 2");
		close(fd[0]);
		close(outfile);
		ft_run_cmd(argv[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		child1;
	int		child2;

	child1 = 0;
	child2 = 0;
	if (ft_arg_check(argc, argv) > 0)
		return (1);
	ft_pipex_init(fd, child1, argv, envp);
	waitpid(child1, NULL, 0);
	ft_pipex_close(fd, child2, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(child2, NULL, 0);
	return (0);
}
