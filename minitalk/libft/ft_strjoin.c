/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:01:28 by emetaj            #+#    #+#             */
/*   Updated: 2022/11/07 15:02:49 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
	{
		return (0);
	}
	ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ptr == 0)
		return (0);
	ft_strlcpy(ptr, s1, len1 + 1);
	ft_strlcpy(ptr + len1, s2, len2 + 1);
	return (ptr);
}

/*
int main(void)
{
	char s1[] = "peanut";
	char s2[] = "butter";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
