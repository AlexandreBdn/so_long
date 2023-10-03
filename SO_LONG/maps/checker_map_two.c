/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:05:47 by abaudin           #+#    #+#             */
/*   Updated: 2023/10/02 17:05:48 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

// void check_exit(t_game *game)
// {
//     int pos_y;
//     int pos_x;

//     pos_y = game->pos.y / game->img.img_width;
//     pos_x = game->pos.x / game->img.img_height;

//     if (game->content.count_c != 0)
//     {   
//         ft_printf("3\n");
//             if (game->content.count_e != 0 && game->map[pos_y][pos_x] == game->content.count_e)
//             {
//                 ft_printf("4\n");
//                 game->map[pos_y][pos_x] = game->content.exit;
//             }
//     }
// }