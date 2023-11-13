/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 07:00:19 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/01 07:00:23 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	close_solong(t_game *game)
{
	end(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	return (2);
}

int	key_hook(int key, t_game *game)
{
	(void) game;
	if (key == escape)
		close_solong(game);
	if (key == height)
		mov_top(game);
	if (key == down)
		mov_bot(game);
	if (key == left)
		mov_left(game);
	if (key == right)
		mov_right(game);
	ft_printf("movement %d\n", game->movement);
	render(game);
	//ft_printf("echap -> %d\n",key);
	return (0);
}

int	end(t_game *game)
{
	int		i;

	i = 0;
	if (game->map != NULL)
	{
		while (game->map[i] != NULL)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		mlx_destroy_image(game->mlx_ptr, game->img.img_wall);
		mlx_destroy_image(game->mlx_ptr, game->img.img_floor);
		mlx_destroy_image(game->mlx_ptr, game->img.img_collect);
		mlx_destroy_image(game->mlx_ptr, game->img.img_player);
		mlx_destroy_image(game->mlx_ptr, game->img.img_exit);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

int	main(int argc, char **str)
{
	t_game	game;

	if (argc != 2)
	{
		ft_error("Error\nThis programe take 1 argumet .ber\n");
		return (0);
	}
	else
	{
		game.movement = 0;
		game.mlx_ptr = mlx_init();
		setting(&(game.content));
		game.map = map_core(str, &game);
		if (game.map != NULL)
		{
			setting_img(&game);
			heart_maps(&game);
		}
		else
		{
			close_solong(&game);
			free(game.map);
		}
	}
	return (0);
}
