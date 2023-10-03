/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:20:52 by abaudin           #+#    #+#             */
/*   Updated: 2023/04/13 09:20:53 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_strchr_int(char *str, char *cmp)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (cmp[y] == '\0' && str[i] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + y] == cmp[y] && str[i + y] && cmp[y])
			y++;
		if (cmp[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}
