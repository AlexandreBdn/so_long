/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:36:30 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/14 15:36:31 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_stradd(char *str, char buff)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buff;
	ret[++i] = '\0';
	return (ret);
}

int	ft_gnl(int fd, char **str)
{
	char	buff;
	int		ret;

	ret = read(fd, &buff, 1);
	while (ret > 0)
	{
		*str = ft_stradd(*str, buff);
		if (buff == '\n')
			return (ret);
		else
			ret += 1;
		ret = read(fd, &buff, 1);
	}
	if (ret == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}
