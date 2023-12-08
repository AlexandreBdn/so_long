/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:34:01 by abaudin           #+#    #+#             */
/*   Updated: 2023/11/14 14:34:02 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void	check_aroud_p2(t_game *game, int y, int x)
{
	if (game->copy_map[y + 1][x] != '1' &&
		game->copy_map[y + 1][x] != '2' &&
		game->copy_map[y + 1][x] != 'V' &&
		game->copy_map[y + 1][x] != 'E')
	{
		y++;
		game->copy_map[y][x] = '2';
		check_aroud_p(game, y, x);
		y--;
	}
	if (game->copy_map[y][x - 1] != '1' &&
		game->copy_map[y][x - 1] != '2' &&
		game->copy_map[y][x - 1] != 'V' &&
		game->copy_map[y][x - 1] != 'E')
	{
		x--;
		game->copy_map[y][x] = '2';
		check_aroud_p(game, y, x);
		x++;
	}
}

void	check_aroud_p(t_game *game, int y, int x)
{
	if (game->copy_map[y - 1][x] != '1' &&
		game->copy_map[y - 1][x] != '2' &&
		game->copy_map[y - 1][x] != 'V' &&
		game->copy_map[y - 1][x] != 'E')
	{
		y--;
		game->copy_map[y][x] = '2';
		check_aroud_p(game, y, x);
		y++;
	}
	if (game->copy_map[y][x + 1] != '1' &&
		game->copy_map[y][x + 1] != '2' &&
		game->copy_map[y][x + 1] != 'V' &&
		game->copy_map[y][x + 1] != 'E')
	{
		x++;
		game->copy_map[y][x] = '2';
		check_aroud_p(game, y, x);
		x--;
	}
	check_aroud_p2(game, y, x);
}

int	ft_checker_pathvalid(t_game *game)
{
	int	y;
	int	x;
	int	flag;

	y = 0;
	flag = 1;
	while (game->copy_map[y] != NULL)
	{
		x = 0;
		while (game->copy_map[y][x] != '\0')
		{
			if (game->copy_map[y][x] == game->content.player)
			{
				check_aroud_p(game, y, x);
				flag = 2;
			}
			if (flag == 2 && game->copy_map[y][x] == game->content.collect)
				return (0);
			x++;
		}
		y++;
	}
	free_map_no_launch(game->copy_map);
	free(game->copy_map);
	return (1);
}

int	check_symbols(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] != 'E' && game->map[y][x] != 'C'
			&& game->map[y][x] != 'P' && game->map[y][x] != '1'
			&& game->map[y][x] != '0' && game->map[y][x] != 'V')
			{
				ft_error("Error, unknown symbols\n");
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
