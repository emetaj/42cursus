/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:21:04 by emetaj            #+#    #+#             */
/*   Updated: 2023/05/10 14:46:31 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

long	ft_handle_sign(char *nptr, int *i)
{
	long	sign;

	sign = 1;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_check_overflow(long sign, unsigned long long res,
	char nptr)
{
	if ((sign > 0 && ((res > INT_MAX / 10)
				|| (res == INT_MAX / 10 && (nptr - '0') > INT_MAX % 10)))
		|| (sign < 0 && ((res > INT_MAX / 10)
				|| (res == INT_MAX / 10 && (nptr - '0') > INT_MAX % 10 + 1))))
	{
		return (1);
	}
	return (0);
}

long	ft_atol(char *nptr, t_stacks *s, char **tmp)
{
	int					i;
	long				sign;
	unsigned long long	res;
	int					j;

	i = 0;
	res = 0;
	while (ft_is_space(nptr[i]))
		i++;
	sign = ft_handle_sign(nptr, &i);
	while (nptr[i])
	{
		j = ft_check_overflow(sign, res, nptr[i]);
		if (j)
			free_parsedwords(s, tmp);
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			free_errormsg(s, "Error\n");
		res = res * 10 + (nptr[i++] - '0');
		j = 0;
	}
	return ((int)(res * sign));
}
