/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:29:13 by emetaj            #+#    #+#             */
/*   Updated: 2023/01/30 13:42:32 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_controller(char conv, va_list *va)
{
	int	ret;

	ret = 0;
	if (conv == 'c')
		ret += ft_putchar(va_arg(*va, int));
	if (conv == '%')
		ret += ft_putchar("%");
	if (conv == 'd' || conv == 'i')
		ret += print_int(va_arg(*va, int));
	if (conv == 'u')
		ret += print_utint(va_arg(*va, unsigned int));
	if (conv == 'x' || conv == 'X')
		ret += print_hex(va_arg(*va, unsigned int), conv);
	if (conv == 'p')
	{
		ret += print_ptr(va_arg(*va, unsigned long int));
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
			ret += ft_controller(format[i], &va);
		}
		i++;
	}
	va_end(va);
	return (ret);
}

#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main() {
    char c = 'A';
    int d = 123;
    unsigned int u = 456;
    char *s = "string";
    void *p = &d;

    ft_printf("Test 1: char: %c\n", c);
	printf("   %i   " , printf("Comparison: %c\n", c));
	printf("\n");


   /* ft_printf("Test 2: %%: %%%%\n");
	printf("Comparison: %%%%\n");
	printf("\n");
    ft_printf("Test 3: int: %d\n", d);
	printf("Comparison: %d\n", d);
	printf("\n");
    ft_printf("Test 4 : int: %i\n", d);
	printf("Comparison: %i\n", d);
	printf("\n");
    ft_printf("Test 5: unsigned int: %u\n", u);
	printf("Comparison: %u\n", u);
	printf("\n");
    ft_printf("Test 6: hex lowercase: %x\n", d);
	printf("Comparison: %x\n", d);
	printf("\n");
    ft_printf("Test 7: hex uppercase: %X\n", d);
	printf("Comparison: %X\n", d);
	printf("\n");
    ft_printf("Test 8: pointer: %p\n", p);
	printf("Comparison: %p\n", p);
	printf("\n");
    ft_printf("Test 9: string: %s\n", s);
	printf("Comparison: %s\n", s);
	printf("\n");
    ft_printf("Test 10: max int: %d\n", INT_MAX);
	printf("Comparison: %d\n", INT_MAX);
	printf("\n");
    ft_printf("Test 11: min int: %d\n", INT_MIN);
	printf("Comparison: %d\n", INT_MIN);*/

    return (0);
}

