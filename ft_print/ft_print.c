/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:36:59 by emetaj            #+#    #+#             */
/*   Updated: 2023/01/27 19:48:42 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int counter(unsigned long int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void put_print_p(unsigned long int n)
{
	if (n >= 16)
	{
		put_print_p(n / 16);
		put_print_p(n % 16);
	}
	if (n < 16)
	{
		if (n < 10)
			print_c(n + '0');
		else
			print_c(n + ('a' - 10));
	}
}

int print_p(unsigned long int n)
{
	int ret;

	ret = 0;
	if (n == 0)
	{
		return (write(1, "(nil)", 5));
	}
	ret += print_s("0x");
	if (n != 0)
	{
		put_print_p(n);
		ret += counter(n);
	}
	return (ret);
}

int print_h(unsigned int n, char h)
{
	int ret;

	ret = 0;
	if (n >= 16)
	{
		ret += print_h(n / 16, h);
		ret += print_h(n % 16, h);
	}
	if (n < 16)
	{
		if (n < 10)
			ret += print_c(n + '0');
		else
		{
			if (h == 'x')
				ret += print_c(n + ('a' - 10));
			else
				ret += print_c(n + ('A' - 10));
		}
	}
	return (ret);
}

int print_s(char *s)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		ret++;
		i++;
	}
	return (ret);
}
