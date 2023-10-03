/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:01:15 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/19 15:01:16 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include "../so_long.h"

void put_image(t_game *game,void *img,int x,int y)
{
	mlx_put_image_to_window(game->mlx_ptr,game->win_ptr, img,
						game->img.img_height * x, game->img.img_width * y); 
}

void print_background(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(game->map[y] != NULL)
	{
		while(game->map[y][x] != '\0')
		{
			if(game->map[y][x] == game->content.wall)
				put_image(game,game->img.img_wall, x, y);
			if(game->map[y][x] == game->content.floor)
				put_image(game,game->img.img_floor, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void print_remainder(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(game->map[y] != NULL)
	{
		while(game->map[y][x] != '\0')
		{
			if (game->map[y][x] == game->content.player)
			{
				game->pos.x = x * game->img.img_height;
				game->pos.y = y * game->img.img_width;
				put_image(game,game->img.img_player,x,y);
			}
			if (game->map[y][x] == game->content.collect)
				put_image(game,game->img.img_collect,x,y);
			if (game->map[y][x] == game->content.exit)
				put_image(game,game->img.img_exit,x,y);
			x++;
		}
		x = 0;
		y++;
	}
}

int render(t_game *game)
{
	print_background(game);
	print_remainder(game);
	return (0);
}

void heart_maps(t_game *game)
{
	 game->win_ptr = mlx_new_window(game->mlx_ptr,(game->width * game->img.img_width),
	       (game->height * game->img.img_height), "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		return ;
	}
	render(game);
	mlx_key_hook(game->win_ptr,key_hook,game);
	mlx_hook(game->win_ptr,17,1L<<17,close_solong,game);
	mlx_loop(game->mlx_ptr);
	end(game);
}