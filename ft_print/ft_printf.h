/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:01:24 by emetaj            #+#    #+#             */
/*   Updated: 2023/01/14 13:33:44 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_c(char c);
int	ft_printer(char conv, va_list *va);
int	ft_printf(const char *format, ...);
int	print_p(unsigned long int n);
int	print_n(int n);
int	print_n2(unsigned int n);
int	print_h(unsigned int n, char h);
int	print_s(char	*s);
#endif
