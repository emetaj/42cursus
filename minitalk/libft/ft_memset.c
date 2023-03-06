/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:45:30 by emetaj            #+#    #+#             */
/*   Updated: 2022/11/07 11:51:42 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i++] = (unsigned char)c;
	}
	return (b);
}

//
//incl stdio und string.h
//int main(void)
//{
//	char str[50];
//	strcpy(str, "Imaa test this bad boi");
//	puts(str);
//	ft_memset(str, '$', 7);
//	puts(str);
//}
