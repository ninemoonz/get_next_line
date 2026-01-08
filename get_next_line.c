/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2026/01/08 13:07:47 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *str, int init)
{
	int		i;
	char	*tmp_str;
	char	c;

	i = 0;
	c = (char)init;
	tmp_str = (char *)str;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&tmp_str[i]);
		i++;
	}
	if (str[i] == c)
		return ((char *)&tmp_str[i]);
	return (NULL);
}

static char	*extract_line(char *line_chunk)
{
	char		*stash;
	ssize_t		i;

	i = 0;
	while (line_chunk[i] != '\n' && line_chunk[i] != '\0')
		i++;
	if (line_chunk[i] == '\0')
		return (NULL);
	stash = ft_substr(line_chunk, i + 1, ft_strlen(line_chunk) - i);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line_chunk[i + 1] = '\0';
	return (stash);
}

static char	*fill_until_nl(int fd, char *stash, char *buffer)
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
		return (free(buffer), NULL);
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
// 	char *res;
// 	int i;
// 	fd = open("test.txt", O_RDONLY);
// 	i = 0;
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	close(fd);
// 	return (0);
// }