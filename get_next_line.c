/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:52:43 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/09 14:13:16 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

// char *get_next_line(int fd)
// {

// }
static char *str = "Hello World";
static int nbr;

void test_global(void)
{
    printf("%s\n", str);
    printf("%d\n", nbr);
}

int main (void)
{
    test_global();
    str = "Bye World";
    nbr = 1;
    test_global();
    return (0);
}