/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:54:50 by abaudin           #+#    #+#             */
/*   Updated: 2023/05/10 14:54:51 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_free(char *chaine, char *buf)
{
	char	*temp;

	temp = ft_strjoin(chaine, buf);
	free(chaine);
	return (temp);
}

char	*ft_get_line(char *chaine)
{
	char	*save;
	int		i;

	i = 0;
	if (!chaine [i])
		return (NULL);
	while (chaine[i] && chaine[i] != '\n')
		i++;
	save = ft_calloc(sizeof(char), i + 2);
	if (!save)
		return (NULL);
	i = 0;
	while (chaine[i] && chaine [i] != '\n')
	{
		save[i] = chaine [i];
		i++;
	}
	if (chaine[i] == '\n' && chaine[i])
		save[i++] = '\n';
	return (save);
}

char	*ft_stock(char *chaine)
{
	int		i;
	int		c;
	char	*stock;

	i = 0;
	c = 0;
	while (chaine[i] && chaine[i] != '\n')
		i++;
	if (!chaine[i])
	{
		free(chaine);
		return (NULL);
	}
	stock = ft_calloc(sizeof(char), (ft_strlen(chaine) - i + 1));
	if (!stock)
		return (NULL);
	i++;
	while (chaine[i])
		stock[c++] = chaine[i++];
	free (chaine);
	return (stock);
}

char	*ft_read_and_save(int fd, char *chaine)
{
	char	*buff;
	int		read_bytes;

	if (!chaine)
		chaine = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_bytes] = 0;
		chaine = ft_free(chaine, buff);
		if (ft_strchr(chaine, '\n'))
			break ;
	}
	free (buff);
	return (chaine);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*chaine;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	chaine = ft_read_and_save(fd, chaine);
	if (!chaine)
		return (NULL);
	line = ft_get_line(chaine);
	chaine = ft_stock(chaine);
	return (line);
}
