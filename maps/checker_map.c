/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:38:48 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/19 16:38:49 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_checker_content(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == game->content.player)
				game->content.count_p = game->content.count_p + 1;
			if (game->map[y][x] == game->content.exit)
				game->content.count_e = game->content.count_e + 1;
			if (game->map[y][x] == game->content.collect)
				game->content.count_c = game->content.count_c + 1;
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_check_col(char *map_line, char wall, t_game *game)
{
	int		i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		ft_error("Error\nMap not close\n");
		return (0);
	}
	game->width = i;
	return (1);
}

int	ft_check_line(char *map_line, char wall)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			ft_error("Error\nMap not close\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_collect(t_game *game)
{
	if (game->content.count_c == 0)
	{
		if (game->content.count_e == 0)
		{
			ft_printf("Game Win\nnumber mouvement : %d\n", game->movement);
			close_solong(game);
		}
	}
}

int	checker_map(t_game *game)
{
	int	y;
	int	x;
	int	l;

	x = 0;
	y = 0;
	l = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
			x++;
		l = x;
		x = 0;
		y++;
	}
	if (l == y)
	{
		ft_error("Error\nMap not Rectangle\n");
		return (1);
	}
	return (0);
}
