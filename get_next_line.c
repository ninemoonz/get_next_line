/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/17 15:16:24 by kkweon           ###   ########.fr       */
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

static char	*fill_until_nl(int fd, char *left_c, char *buffer)
{
	ssize_t rd_len;
	char *tmp;

	rd_len = 1;
	while (rd_len > 0)
	{
		rd_len = read(fd, buffer, BUFFER_SIZE);
		if (rd_len == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (rd_len == 0)
			break;
		buffer[rd_len] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(left_c, '\n'))
			break;
	}
	return (left_c);
}
char *get_next_line(int fd)
{
	static char *left_c;
	char *line;
	char *buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_until_nl(fd, left_c, buffer);
	return (line);
}

int main (void)
{
	int fd;
	char *res;

	fd = open("test.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s\n", res);
	close(fd);
	return (0);
}
