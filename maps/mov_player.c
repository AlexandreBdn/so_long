/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:15:49 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/18 15:15:51 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img,
		game->img.img_height * x, game->img.img_width * y);
}

void	mov_top(t_game *game)
{
	int	pos_y;
	int	pos_x;

	pos_y = game->pos.y / game->img.img_width;
	pos_x = game->pos.x / game->img.img_height;
	if (game->map[pos_y - 1][pos_x] == game->content.collect)
		game->content.count_c = game->content.count_c - 1;
	if (game->map[pos_y - 1][pos_x] == game->content.enemy)
	{
		ft_printf("You Loose\n");
		close_solong(game);
	}
	if (game->map[pos_y - 1][pos_x] == game->content.exit &&
			game->content.count_c == 0)
		game->content.count_e = game->content.count_e - 1;
	if ((game->map[pos_y - 1][pos_x] != game->content.wall) &&
		(game->map[pos_y - 1][pos_x] != game->content.exit &&
		game->content.count_e != 0))
	{
		game->map[pos_y - 1][pos_x] = game->content.player;
		game->map[pos_y][pos_x] = game->content.floor;
		game->movement += 1;
	}
	game->player_mov = 1;
	check_collect(game);
}

void	mov_bot(t_game *game)
{
	int	pos_y;
	int	pos_x;

	pos_y = game->pos.y / game->img.img_width;
	pos_x = game->pos.x / game->img.img_height;
	if (game->map[pos_y + 1][pos_x] == game->content.collect)
		game->content.count_c = game->content.count_c - 1;
	if (game->map[pos_y + 1][pos_x] == game->content.enemy)
	{
		ft_printf("You Loose\n");
		close_solong(game);
	}
	if (game->map[pos_y + 1][pos_x] == game->content.exit &&
			game->content.count_c == 0)
		game->content.count_e = game->content.count_e - 1;
	if ((game->map[pos_y + 1][pos_x] != game->content.wall) &&
		(game->map[pos_y + 1][pos_x] != game->content.exit &&
		game->content.count_e != 0))
	{
		game->map[pos_y + 1][pos_x] = game->content.player;
		game->map[pos_y][pos_x] = game->content.floor;
		game->movement += 1;
	}
	game->player_mov = 2;
	check_collect(game);
}

void	mov_right(t_game *game)
{
	int	pos_y;
	int	pos_x;

	pos_y = game->pos.y / game->img.img_width;
	pos_x = game->pos.x / game->img.img_height;
	if (game->map[pos_y][pos_x + 1] == game->content.collect)
		game->content.count_c = game->content.count_c - 1;
	if (game->map[pos_y][pos_x + 1] == game->content.enemy)
	{
		ft_printf("You Loose\n");
		close_solong(game);
	}
	if (game->map[pos_y][pos_x + 1] == game->content.exit &&
			game->content.count_c == 0)
		game->content.count_e = game->content.count_e - 1;
	if (game->map[pos_y][pos_x + 1] != game->content.wall &&
		game->map[pos_y][pos_x + 1] != game->content.exit &&
		game->content.count_e != 0)
	{
		game->map[pos_y][pos_x + 1] = game->content.player;
		game->map[pos_y][pos_x] = game->content.floor;
		game->movement += 1;
	}
	game->player_mov = 3;
	check_collect(game);
}

void	mov_left(t_game *game)
{
	int	pos_y;
	int	pos_x;

	pos_y = game->pos.y / game->img.img_width;
	pos_x = game->pos.x / game->img.img_height;
	if (game->map[pos_y][pos_x - 1] == game->content.collect)
		game->content.count_c = game->content.count_c - 1;
	if (game->map[pos_y][pos_x - 1] == game->content.enemy)
	{
		ft_printf("You Loose\n");
		close_solong(game);
	}
	if (game->map[pos_y][pos_x - 1] == game->content.exit &&
			game->content.count_c == 0)
		game->content.count_e = game->content.count_e - 1;
	if ((game->map[pos_y][pos_x - 1] != game->content.wall) &&
		(game->map[pos_y][pos_x - 1] != game->content.exit &&
		game->content.count_e != 0))
	{
		game->map[pos_y][pos_x - 1] = game->content.player;
		game->map[pos_y][pos_x] = game->content.floor;
		game->movement += 1;
	}
	game->player_mov = 4;
	check_collect(game);
}
