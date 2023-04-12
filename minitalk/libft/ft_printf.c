/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:29:13 by emetaj            #+#    #+#             */
/*   Updated: 2023/02/02 13:56:30 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_int(int n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret++;
		write(1, "-", 1);
		n *= -1;
	}
	return (print_uint(n) + ret);
}

int	print_uint(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
	{
		ret += print_uint(n / 10);
		ret += print_uint(n % 10);
	}
	if (n < 10)
		ret += ft_putchar(n + '0');
	return (ret);
}

int	ft_controller(char conv, va_list *arg_list)
{
	int	ret;

	ret = 0;
	if (conv == 'c')
		ret += ft_putchar(va_arg(*arg_list, int));
	else if (conv == '%')
		ret += ft_putchar('%');
	else if (conv == 'd' || conv == 'i')
		ret += print_int(va_arg(*arg_list, int));
	else if (conv == 'u')
		ret += print_uint(va_arg(*arg_list, unsigned int));
	else if (conv == 'x' || conv == 'X')
		ret += +(va_arg(*arg_list, unsigned int), conv);
	else if (conv == 'p')
	{
		ret += print_ptr(va_arg(*arg_list, unsigned long int));
	}
	else if (conv == 's')
		ret += print_s(va_arg(*arg_list, char *));
	else
	{
		return (0);
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		i;
	va_list	arg_list;

	ret = 0;
	i = 0;
	va_start(arg_list, format);
	while (format[i])
	{
		if (format [i] != '%')
		{
			write(1, &format[i], 1);
			ret++;
		}
		if (format [i] == '%')
		{
			i++;
			ret += ft_controller(format[i], &arg_list);
		}
		i++;
	}
	va_end(arg_list);
	return (ret);
}
