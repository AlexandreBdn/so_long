/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prc_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:27:12 by abaudin           #+#    #+#             */
/*   Updated: 2023/05/05 01:27:13 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexa(int n)
{
	unsigned int	unb;
	char			c[12];
	char			*hexa;
	int				count;	
	int				i;

	count = 0;
	hexa = "0123456789abcdef";
	unb = n;
	i = 0;
	while (unb != 0)
	{
		c[i] = hexa[unb % 16];
		unb = unb / 16;
		count++;
		i++;
	}
	while (i-- > 0)
		ft_putchar(c[i]);
	if (n == 0)
	{
		write(1, "0", 1);
		count++;
	}
	return (count);
}
