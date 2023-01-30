/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:36:59 by emetaj            #+#    #+#             */
/*   Updated: 2023/01/30 13:35:59 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counter(unsigned long int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	print_adress(unsigned long int n)
{
	if (n >= 16)
	{
		print_adress(n / 16);
		print_adress(n % 16);
	}
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n + ('a' - 10));
	}
}

int	print_ptr(unsigned long int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
	{
		return (ft_putchar("(nil)"));
	}
	ret += print_s("0x");
	if (n != 0)
	{
		print_adress(n);
		ret += counter(n);
	}
	return (ret);
}

int	print_hex(unsigned int n, char h)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += print_hex(n / 16, h);
		ret += print_hex(n % 16, h);
	}
	if (n < 16)
	{
		if (n < 10)
			ret += ft_putchar(n + '0');
		else
		{
			if (h == 'x')
				ret += ft_putchar(n + ('a' - 10));
			else
				ret += ft_putchar(n + ('A' - 10));
		}
	}
	return (ret);
}

int	print_s(char *s)
{
	int	ret;
	int	i;

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
