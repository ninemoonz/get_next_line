/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/17 15:02:48 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char *extract_nl(char *chunk)
// {
	
// }

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

static char	*fill_until_nl(int fd, char *line_chunk, char *stash)
{
	ssize_t rd_len;
	char *tmp;

	rd_len = 1;
	while (rd_len > 0)
	{
		rd_len = read(fd, stash, BUFFER_SIZE);
		if (rd_len == -1)
			return (free(stash), NULL);
		else if (rd_len == 0)
			break;
		stash[rd_len] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, stash);
		if (ft_strchr(stash, '\n'))
			break;
	}
	return (stash);
}
char *get_next_line(int fd)
{
	static char *new_line;
	char *line_chunk;
	char *buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line_chunk = NULL;
	line_chunk = fill_until_nl(fd, line_chunk, buffer);
	return (line_chunk);
}

int main (void)
{
	int fd;
	char *res;

	fd = open("test.txt", O_RDONLY);

	res = get_next_line(fd);
	printf("result: %s\n", res);
	res = NULL;

	close(fd);
	return (0);
}
