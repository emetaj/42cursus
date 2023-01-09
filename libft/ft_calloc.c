/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:35:44 by emetaj            #+#    #+#             */
/*   Updated: 2022/11/07 14:41:24 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	n, size_t	size)
{
	size_t	i;
	void	*arr;

	i = n * size;
	arr = (void *)malloc(i);
	if (arr == 0)
		return (0);
	ft_bzero(arr, i);
	return (arr);
}
