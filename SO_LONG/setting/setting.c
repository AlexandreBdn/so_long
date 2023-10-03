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

void setting(t_item *content)
{
    content->player = 'P';
    content->exit = 'E';
    content->collect = 'C';
    content->wall = '1';
    content->floor = '0';
    content->count_p = 0;
    content->count_e = 0;
    content->count_c = 0;
}

void setting_img(t_game *game)
{
    game->img.img_height = 50;
    game->img.img_width = 50;
    game->img.floor = "asset/floor/floor_grass.xpm";
    game->img.wall = "asset/wall/Wall1.xpm";
    game->img.player = "asset/player/Cat1.xpm";
    game->img.collect = "asset/collect/lait_1.xpm";
    game->img.exit = "asset/exit/exit.xpm";
    game->img.img_floor = mlx_xpm_file_to_image(game->mlx_ptr,game->img.floor,
                                &(game->img.img_width), &(game->img.img_height));
    game->img.img_wall = mlx_xpm_file_to_image(game->mlx_ptr,game->img.wall,
                                &(game->img.img_width), &(game->img.img_height));
    game->img.img_player = mlx_xpm_file_to_image(game->mlx_ptr,game->img.player,
                                &(game->img.img_width), &(game->img.img_height));
    game->img.img_exit = mlx_xpm_file_to_image(game->mlx_ptr,game->img.exit,
                                &(game->img.img_width), &(game->img.img_height));
    game->img.img_collect = mlx_xpm_file_to_image(game->mlx_ptr,game->img.collect,
                                &(game->img.img_width), &(game->img.img_height));
}