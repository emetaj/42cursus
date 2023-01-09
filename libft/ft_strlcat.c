/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:36:14 by emetaj            #+#    #+#             */
/*   Updated: 2022/11/07 12:44:27 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	h;
	size_t	s;

	h = 0;
	s = 0;
	while (dst[h] && h < size)
		h++;
	while (src[s] && (h + s + 1) < size)
	{
		dst[h + s] = src[s];
		s++;
	}
	if (h < size)
		dst[h + s] = '\0';
	return (h + ft_strlen(src));
}
