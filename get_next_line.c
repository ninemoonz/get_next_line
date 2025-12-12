/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/12 15:14:31 by kkweon           ###   ########.fr       */
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
	return (NULL);
}

char	*get_next_line(int fd)
{
	int		line_len;
	char	*buff;
	char	*tmp;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL || BUFFER_SIZE <= 0)
		return (NULL);
	line_len = read(fd, buff, BUFFER_SIZE);
	if (line_len <= 0)
		return (free(buff), NULL);
	buff[line_len] = '\0';
	tmp = left_str(buff);
	return (tmp);
}

int main (void)
{
	int fd;
	int count;
	char *res;

	fd = open("test.txt", O_RDONLY);
	printf("[fd No.]: %d\n", fd);
	res= get_next_line(fd);
	count = 1;
	printf("[Final result %d]: %s\n", count++, res);
	printf("[Final result %d]: %s\n", count++, res);
	printf("[Final result %d]: %s\n", count++, res);
	close(fd);
	return (0);
}
