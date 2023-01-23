/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:33:19 by emetaj            #+#    #+#             */
/*   Updated: 2023/01/10 13:33:21 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!str1)
	{
		str1 = malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (0);
	str = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = -1;
	c = 0;
	if (str1)
		while (str1[++i] != '\0')
			str[i] = str1[i];
	while (str2[c] != '\0')
		str[i++] = str2[c++];
	str[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (str);
}
