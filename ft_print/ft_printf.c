/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:36:59 by emetaj            #+#    #+#             */
/*   Updated: 2022/12/20 16:51:44 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_print *ft_initialise_tab(t_print *tab)
{
	tab->len = 0;
	return (tab);
}

void	ft_conv(char c, t_print *tab)
{
	if (c == 'c')
		ischar(tab);
	else if (c == 's')
		isstring(tab)
	else if (c == 'p')
		ispointer(tab);
	else if (c == 'd' || c == 'i')
		isint(tab);
	else if (c == 'u')
		isdecint(tab);
	else if (c == 'X')
		ishexmaj(tab);
	else if (c == 'x')
		ishexmin(tab);
	else if (c == '%')
		isperc(tab);
}

int	ft_printf(const char *input, ...)
{
	t_print *tab;
	int	i;

	tab = malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab = ft_initialise_tab(tab);
	i = 0;
	va_start(tab->args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			if (ft_strcjr("cspdiuxX%", input[i + 1]))
				ft_conv(input[i++ + 1], tab);
		}
		else
		{
			ft_putchar(input[i]);
			tab->len++;
		}
		i++;
	}
	free(tab);
	return (tab->len);
}
