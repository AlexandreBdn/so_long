/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:38:15 by abaudin           #+#    #+#             */
/*   Updated: 2023/04/26 13:38:15 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = malloc(sizeof (char) * ft_strlen(s) + 1);
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
