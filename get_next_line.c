/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:28:32 by koodal            #+#    #+#             */
/*   Updated: 2026/01/16 17:23:24 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_nl(char *line)
{
    char *remainder;
    int i;
    
    i = 0;
    while (line[i] != '\n' && line[i] != '\0')
        i++;
    if (line[i] == '\0')
        return (NULL);
    remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
    line[i + 1] = '\0';
    return (remainder);
}

char *until_nl(int fd, char *buffer, char *stash)
{
    char *tmp;
    int rd_bytes;
    
    if (fd <= 0)
        return (NULL);
    rd_bytes = 1;
    while (rd_bytes > 0)
    {
        rd_bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[rd_bytes] = '\0';
        if (stash == NULL)
            stash = ft_strdup("");
        tmp = stash;
        stash = ft_strjoin(tmp, buffer);
        free(tmp);
        tmp = NULL;
        if (ft_strchr(stash, '\n'))
            break ;
    }
    return (stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line_until_nl;
    char *buffer;
    
    if (fd < 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    line_until_nl = until_nl(fd, buffer, stash);
    stash = extract_nl(line_until_nl);
    free(buffer);
    buffer = NULL;
    return (line_until_nl);    
}

int main (void)
{
    int fd;
    char *str;

    fd = open("test.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    close(fd);
    return (0);
}
