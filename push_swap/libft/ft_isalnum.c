/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:00:32 by emetaj            #+#    #+#             */
/*   Updated: 2022/11/07 11:08:47 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
//
//int main(void)
//{
//	printf("%d", ft_isalnum('/'));
//	printf("%d", ft_isalnum('F'));
//	printf("%d", ft_isalnum(6));
//}
