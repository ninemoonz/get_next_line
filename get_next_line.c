/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/12 14:03:01 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *left_str(char *left)
{
	int i;
	int j;
	char *tmp;
	char *res;

	i = 0;
	j = 0;
	tmp = left;
	while (tmp[i])
	{
		if (tmp[i] == '\\' && tmp[i + 1] == 'n')
		{
			res = ft_substr(tmp, j, (size_t)i);
			return (tmp);
		}
		else
			i++;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	int line_len;
	char *buff;
	char *str_dup;
	char *tmp;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buff == NULL || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = left_str(buff);
	line_len = read(fd, tmp, BUFFER_SIZE);
	if (line_len <= 0)
	{
		free(buff);
		return (NULL);
	}

	return (tmp);
}

int main (void)
{
	int fd;
	char *res;
	fd = open("test.txt", O_RDONLY);
	res= get_next_line(fd);
	
	printf("%s\n", res);
	close(fd);
	return (0);
}
