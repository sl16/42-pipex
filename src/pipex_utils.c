/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:54:28 by vbartos           #+#    #+#             */
/*   Updated: 2023/08/29 11:21:25 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

//entry checks
int	ft_arg_check(int argc, char **argv)
{
	if (argc != 5)
	{
		perror("Invalid number of arguments (correct = 4)");
		ft_printf("Usage: %s <infile> <cmd 1> <cmd 2> <outfile>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], F_OK | R_OK) != 0)
	{
		perror("Infile not provided or not readable");
		ft_printf("Usage: %s <infile> <cmd 1> <cmd 2> <outfile>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

//free array of arrays in case executable paths not found
void	ft_free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

//extract all executable paths from environment variable
char	*ft_extract_path(char **envp)
{
	int		i;
	char	*all_paths_str;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			all_paths_str = envp[i];
			break ;
		}
		i++;
	}
	if (!all_paths_str || all_paths_str == NULL)
		perror("Cannot parse path");
	return (all_paths_str + 5);
}
