/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:04:47 by koodal            #+#    #+#             */
/*   Updated: 2026/01/16 17:07:05 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest_mem;
	size_t		i;

	dest_mem = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (i < len)
	{
		dest_mem[i] = s[start];
		i++;
		start++;
	}
	dest_mem[i] = '\0';
	return (dest_mem);
}

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, int init)
{
	int		i;
	char	*tmp_str;

	i = 0;
	tmp_str = (char *)str;
	while (str[i] != '\0')
	{
		if (str[i] == init)
			return (&tmp_str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		tot_len;
	char	*dest;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc((tot_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
