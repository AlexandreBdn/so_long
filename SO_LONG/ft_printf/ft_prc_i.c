/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prc_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:11:27 by abaudin           #+#    #+#             */
/*   Updated: 2023/05/05 01:11:28 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_bis(int n, unsigned int unb, int i, int count)
{
	char			c[12];

	if (n < 0)
	{
		write(1, "-", 1);
		unb = -n;
		count++;
	}			
	while (unb != 0)
	{
		c[i] = (unb % 10) + '0';
		unb = unb / 10;
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

int	ft_putnbr(int n)
{
	int				count;
	unsigned int	unb;
	int				i;

	unb = n;
	i = 0;
	count = 0;
	return (ft_putnbr_bis(n, unb, i, count));
}
