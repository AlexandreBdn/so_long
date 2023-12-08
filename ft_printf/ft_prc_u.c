/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prc_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:24:36 by abaudin           #+#    #+#             */
/*   Updated: 2023/05/05 01:24:36 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_unputnbr( unsigned int n)
{
	char			c[12];
	int				i;
	int				count;

	count = 0;
	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		count++;
	}
	while (n != 0)
	{
		c[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &c[i], 1);
		count++;
	}
	return (count);
}
