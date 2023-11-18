/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:21:27 by vbartos           #+#    #+#             */
/*   Updated: 2023/07/24 09:33:11 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ft_found_newline function description:
-
Searches for newline in provided char array.
-
If found, returns one.
If not found, returns zero.
*/

int	ft_found_newline(char *stash)
{
	int	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
ft_add_to_stash function description:
-
If stash not yet allocated (or freed), allocate it.
-
Joins temp (the overflow from previous line) and line together.
*/

char	*ft_add_to_stash(char *stash, char *buffer)
{
	char	*new_stash;

	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	new_stash = ft_strjoin(stash, buffer);
	free(stash);
	return (new_stash);
}

/*
ft_extract_line function description:
-
Copies contents of stash until newline symbol into line.
Newline may or may not be found.
*/

char	*ft_extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	i += (stash[i] == '\n');
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
ft_trim_stash function description:
-
Allocates trimmed_stash with the size for overflow
(the size of stash from the first newline onwards).
Proceeds to copy the contents.
*/

char	*ft_trim_stash(char *stash)
{
	int		i;
	char	*trimmed_stash;
	int		j;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	i += (stash[i] == '\n');
	trimmed_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!trimmed_stash)
		return (NULL);
	j = 0;
	while (stash[i + j] != '\0')
	{
		trimmed_stash[j] = stash[i + j];
		j++;
	}
	trimmed_stash[j] = '\0';
	free(stash);
	return (trimmed_stash);
}

/*
get_next_line variables description:
- stash: a static variable that stores overflow from previous read() calls;
- line: a char array that holds current line to be returned by get_next_line.
- bytes_read: stores number of bytes (for memory alloc and End of File);

get_next_line function description:
-
Checks for valid file descriptior and buffer size.
-
Allocates memory for current line.
-
Searches for newline in temp with ft_newline_found.
If not found, reads from file descriptor using read()
and stores the contents in buffer. Then adds that to
stash (which can now be stash + buffer).
-
Extracts the line from stash and trims the chars
that are now extra in stash.
----------
Bonus part description:
- stash is now an array of arrays, allowing for multiple file descriptors
	to be tracked.
*/

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash[1024];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (ft_found_newline(stash[fd]) == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash[fd] = ft_add_to_stash(stash[fd], buffer);
	}
	free(buffer);
	buffer = ft_extract_line(stash[fd]);
	stash[fd] = ft_trim_stash(stash[fd]);
	return (buffer);
}
