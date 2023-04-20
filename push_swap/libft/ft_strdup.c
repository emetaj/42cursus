/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:41:42 by emetaj            #+#    #+#             */
/*   Updated: 2022/11/07 14:56:15 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	res = malloc(len + 1);
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "ft_strlen.c"
//int main(void)
//{
//	char *ptr1 = "hallihallo";
//	char *ptr2;
//
//	puts(ptr1);
//	ptr2 = ft_strdup(ptr1);
//	puts(ptr2)
//}
