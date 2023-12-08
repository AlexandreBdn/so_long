/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:20:26 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/18 13:20:27 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	setting(t_item *content)
{
	content->player = 'P';
	content->exit = 'E';
	content->collect = 'C';
	content->wall = '1';
	content->floor = '0';
	content->new_floor = '4';
	content->enemy = 'V';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void	setting_img2(t_game *game)
{
	game->img.playerl = "asset/player/left.xpm";
	game->img.playerh = "asset/player/height.xpm";
	game->img.playerd = "asset/player/down.xpm";
	game->img.img_playerh = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.playerh, &(game->img.img_width), &(game->img.img_height));
	game->img.img_playerd = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.playerd, &(game->img.img_width), &(game->img.img_height));
	game->img.img_playerl = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.playerl, &(game->img.img_width), &(game->img.img_height));
}

void	setting_img(t_game *game)
{
	game->img.img_height = 50;
	game->img.img_width = 50;
	game->img.floor = "asset/floor/Floor.xpm";
	game->img.wall = "asset/wall/Wall.xpm";
	game->img.player = "asset/player/Player.xpm";
	game->img.collect = "asset/collect/star.xpm";
	game->img.exit = "asset/exit/exit1.xpm";
	game->img.enemy = "asset/enemy/enemy1.xpm";
	game->img.img_floor = mlx_xpm_file_to_image(game->mlx_ptr, game->img.floor,
			&(game->img.img_width), &(game->img.img_height));
	game->img.img_wall = mlx_xpm_file_to_image(game->mlx_ptr, game->img.wall,
			&(game->img.img_width), &(game->img.img_height));
	game->img.img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.player, &(game->img.img_width), &(game->img.img_height));
	game->img.img_exit = mlx_xpm_file_to_image(game->mlx_ptr, game->img.exit,
			&(game->img.img_width), &(game->img.img_height));
	game->img.img_collect = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.collect, &(game->img.img_width), &(game->img.img_height));
	game->img.img_enemy = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.enemy, &(game->img.img_width), &(game->img.img_height));
	setting_img2(game);
}

void	setting_mov(t_game *game)
{
	game->player_mov = 0;
	game->movement = 0;
}
