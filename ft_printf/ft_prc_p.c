/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prc_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:21:03 by abaudin           #+#    #+#             */
/*   Updated: 2023/05/05 01:21:04 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexa_p_bis(void *n, int i, unsigned long unb, int count)
{
	char			c[20];
	char			*hexa;

	hexa = "0123456789abcdef";
	if (n == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0", 1);
	write (1, "x", 1);
	while (unb != 0)
	{
		c[i] = hexa[unb % 16];
		unb = unb / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &c[i], 1);
		count++;
	}
	return (count + 2);
}

int	ft_puthexa_p(void *n)
{
	int				count;
	unsigned long	unb;
	int				i;

	unb = (unsigned long int) n;
	i = 0;
	count = 0;
	return (ft_puthexa_p_bis(n, i, unb, count));
}
