/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:00 by emetaj            #+#    #+#             */
/*   Updated: 2023/04/24 15:16:01 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_overflow(long result, long check, int sign, t_stacks *s)
{
	if (sign == 1 && (result < check || result > INT_MAX))
		free_errormsg(s, "Error\n");
	else if (sign == -1 && (-result < INT_MIN || result < check))
		free_errormsg(s, "Error\n");
	return (1);
}

static void	skip_whitespace(const char **str)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
}

static int	check_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

long	ft_atol(const char *str, t_stacks *s)
{
	int		sign;
	long	result;
	long	check;

	skip_whitespace(&str);
	sign = check_sign(&str);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		check = result;
		result = result * 10 + (*str - '0');
		check_overflow(result, check, sign, s);
		str++;
	}
	if (*str != '\0')
		free_errormsg(s, "Error\n");
	return (result * sign);
}
