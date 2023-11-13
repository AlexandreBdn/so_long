/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:14:54 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/11 11:14:55 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = ft_gnl(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = ft_gnl(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	free(buff);
	return (NULL);
}

void	*ft_free_map(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
	return (0);
}

char	**parse_map(int fd, t_game *game)
{
	int	i;

	i = 1;
	game->map = ft_split(get_map(fd), '\n');
	if (checker_map(game) == 1)
	{
		ft_free_map(game);
		return (0);
	}
	ft_checker_content(game);
	if (!(ft_check_line(game->map[0], game->content.wall)))
		return (ft_free_map(game));
	while (game->map[i] != NULL)
	{
		if (!(ft_check_col(game->map[i], game->content.wall, game)))
			return (ft_free_map(game));
		i++;
	}
	if (!(ft_check_line(game->map[i - 1], game->content.wall)))
		return (ft_free_map(game));
	game->height = i;
	return (game->map);
}

char	**map_core(char **str, t_game *game)
{
	int	fd;

	fd = 0;
	game->map = NULL;
	if (ft_strchr_int(str[1], ".ber") == 0)
		return (ft_error("Error\nNo correct format map\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			game->map = parse_map(fd, game);
		else
			return (ft_error("Error\nFailled to open file"));
		if ((game->content.count_c == 0 || game->content.count_e != 1
				|| game->content.count_p != 1) && game->map != NULL)
		{
			ft_free_map(game);
			return (
				ft_error("Error\nNeed 1 player/exitand at least 1 Object\n"));
		}
	}
	return (game->map);
}
