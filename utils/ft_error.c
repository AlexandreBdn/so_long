/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:34:27 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/18 19:34:29 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

void	free_map_no_launch(char **game)
{
	int	i;

	i = 0;
	while (game[i])
	{
		free(game[i]);
		i++;
	}
	game = NULL;
}

int	check_format(t_game *game)
{
	int	y;
	int	x;
	int	k;
	int	l;

	x = 0;
	y = 0;
	k = 0;
	l = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
			x++;
		if (y == 0)
			k = x;
		l = x;
		if (k != l)
		{
			ft_error("Error\nMap not Rectangle\n");
			return (1);
		}
		x = 0;
		y++;
	}
	return (0);
}
