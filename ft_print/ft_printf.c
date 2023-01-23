/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:29:13 by emetaj            #+#    #+#             */
/*   Updated: 2023/01/14 13:37:12 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_n(int n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret++;
		write(1, "-", 1);
		n *= -1;
	}
	return (print_n2(n) + ret);
}

int	print_n2(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
	{
		ret += print_n2(n / 10);
		ret += print_n2(n % 10);
	}
	if (n < 10)
		ret += print_c(n + '0');
	return (ret);
}

int	ft_printer(char conv, va_list *va)
{
	int	ret;

	ret = 0;
	if (conv == 'c')
		ret += print_c(va_arg(*va, int));
	if (conv == '%')
		ret += write(1, "%", 1);
	if (conv == 'd' || conv == 'i')
		ret += print_n(va_arg(*va, int));
	if (conv == 'u')
		ret += print_n2(va_arg(*va, unsigned int));
	if (conv == 'x' || conv == 'X')
		ret += print_h(va_arg(*va, unsigned int), conv);
	if (conv == 'p')
	{
		ret += print_p(va_arg(*va, unsigned long int));
	}
	if (conv == 's')
		ret += print_s(va_arg(*va, char *));
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		i;
	va_list	va;

	ret = 0;
	i = 0;
	va_start(va, format);
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
			ret += ft_printer(format[i], &va);
		}
		i++;
	}
	va_end(va);
	return (ret);
}

//int main(void)
//{
//	#include <limits.h>
// 	#include <stdio.h>
//
//    int    i0 = 2147483647;
//    int    i1 = 2147483647;
//    int    i2 = -42967295;
//    char str[] = "lemts go:      ";
//    ft_printf("f %s %% %d %i %u \n", str, i0, i2, i3);
//    ft_printf("%u\n", 9223372036854775806LL);
//    ft_printf(" %i\n", ft_printf(" %u %u %u %u %u %u %u", 
//	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, -1, -42));
//    printf(" %i\n", printf(" %u %u %u %u %u %u %u", INT_MAX, 
//	INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, -1, -42));
//
//    ft_printf("%u\n", ULONG_MAX);
//    printf("%i\n", ft_printf("%x", 189));
//    ft_printf("\n");
//    printf("%i", printf("%x\n", 189));
//    printf("%lu %lld %lld %lld %d \n", ULONG_MAX, LONG_MAX , 
// 	LONG_MIN, ULONG_MAX - 199, -1);
//    ft_printf(" %i\n", ft_printf("%p %p %p %p %p",ULONG_MAX - 
// 	0, LONG_MAX - 1, LONG_MIN + 1, ULONG_MAX - 200, -1));
//    printf(" %i\n", printf("%p %p %p %p %p",ULONG_MAX - 
//	0, LONG_MAX - 1, LONG_MIN + 1, ULONG_MAX - 200, -1)); 
//}
