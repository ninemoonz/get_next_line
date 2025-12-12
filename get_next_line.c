/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/12 16:50:57 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*left_str(char *left)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	tmp = left;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			res = ft_substr(tmp, 0, (size_t)i);
			return (res);
		}
		i++;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	int		line_len;
	char	*buff;
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	line_len = read(fd, buff, BUFFER_SIZE);
	if (line_len <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[line_len] = '\0';
	tmp = left_str(buff);
	return (tmp);
}

int main (void)
{
	int fd;
	char *res;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break;
		printf("result line: %s\n", res);
		res = NULL;
	}
	close(fd);
	return (0);
}
