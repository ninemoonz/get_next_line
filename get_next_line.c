/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/09 17:01:57 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char buff[11];
	read(fd, buff, 10);
	return (buff);
}

int main (void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
