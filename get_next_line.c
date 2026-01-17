/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2026/01/17 16:23:58 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *line)
{
	char		*remainder;
	ssize_t		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

char	*fill_until_nl(int fd, char *stash, char *buffer)
{
	ssize_t		rd_bytes;
	char		*tmp;

	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(stash), NULL);
		else if (rd_bytes == 0)
			break ;
		buffer[rd_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = fill_until_nl(fd, stash, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	stash = extract_line(line);
	return (line);
}

// int main (void)
// {
// 	int fd;
// 	int i;
// 	char *res;

// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		res = get_next_line(fd);
// 		if (res == NULL)
// 			break;
// 		printf("%s", res);
// 		free(res);
// 	}
// 	close(fd);
// 	return (0);
// }