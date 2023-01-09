/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:51:52 by emetaj            #+#    #+#             */
/*   Updated: 2022/11/07 12:04:12 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_memset.c"
//#include <stdio.h>
//#include <strings.h>
//#include <unistd.h>

#include "libft.h"

void	ft_bzero(void	*s, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}
//
//int main(void)
//{
//	char	dst[7];
//
//	strcpy(dst, "nimmerland");
//	puts(dst);
//	write(1, &dst, 7);
//	puts(dst);
//}
