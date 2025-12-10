/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/10 14:58:34 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// char *newline_check(char *buffer)
// {

// }

char	*get_next_line(int fd)
{
	int fd_r;
	int buff_size;
	char *buff;
	int str_len;
	
	buff_size = 42;
	buff = malloc(buff_size + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	fd_r = read(fd, buff, 42);
	str_len = ft_strlen(buff);
	printf("str_len: %d\n", str_len);
	return (buff);
}



int main (void)
{
	int fd;
	char *res;

	fd = open("test.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s\n", res);
	return (0);
}
