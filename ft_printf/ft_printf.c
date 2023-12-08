/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:28 by abaudin           #+#    #+#             */
/*   Updated: 2023/04/28 17:57:31 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_pourcent(const char symb, va_list args, int count)
{
	if (symb == 'c')
		count = count + (ft_putchar(va_arg(args, int)));
	else if (symb == 's')
		count = count + (ft_printf_s(va_arg(args, char *)));
	else if (symb == 'p')
		count = count + (ft_puthexa_p(va_arg(args, void *)));
	else if (symb == 'd' || symb == 'i')
		count = count + (ft_putnbr(va_arg(args, int)));
	else if (symb == 'u')
		count = count + (ft_unputnbr(va_arg(args, unsigned int)));
	else if (symb == 'x')
		count = count + (ft_puthexa(va_arg(args, unsigned int)));
	else if (symb == 'X')
		count = count + (ft_puthexa2(va_arg(args, unsigned int)));
	else if (symb == '%')
		count = count + (ft_putchar_pourcent());
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count = ft_pourcent(s[i], args, count);
		}
		else
			count = count + ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
