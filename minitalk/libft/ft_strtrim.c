/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:03:13 by emetaj            #+#    #+#             */
/*   Updated: 2022/11/07 15:04:13 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_check(char const *s1, char const *set)
{
	if ((!s1 && !set) || !s1 || *s1 == '\0')
		return (0);
	else
		return (1);
}

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	is1start;
	size_t	isset;
	size_t	is1end;

	is1end = ft_strlen((char *)s1) - 1;
	is1start = 0;
	isset = 0;
	while (is1start <= is1end)
	{
		if (s1[is1start] != set[isset] && set[isset])
			isset++;
		else if (s1[is1start] == set[isset] && set[isset])
		{
			is1start++;
			isset = 0;
		}
		else if (!set[isset])
			break ;
	}
	return (is1start);
}

static size_t	ft_end(char const *s1, char const *set, size_t is1start)
{
	size_t	isset;
	size_t	is1end;

	is1end = ft_strlen((char *)s1) - 1;
	isset = 0;
	while (is1end >= is1start)
	{
		if (s1[is1end] != set[isset] && set[isset])
			isset++;
		else if (s1[is1end] == set[isset] && set[isset])
		{
			is1end--;
			isset = 0;
		}
		else if (!set[isset])
			break ;
	}
	return (is1end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	is1start;
	size_t	is1end;

	if (ft_check(s1, set) == 0 || ft_start(s1, set) == ft_strlen(s1) - 1)
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (0);
		*new = '\0';
		return (new);
	}
	is1start = ft_start(s1, set);
	is1end = ft_end(s1, set, is1start);
	new = malloc(sizeof(char) * (is1end - is1start + 2));
	if (!new)
		return (0);
	ft_memcpy((void *)new,
		(const void *)(s1 + is1start), is1end - is1start + 1);
	new[is1end - is1start + 1] = '\0';
	return (new);
}
