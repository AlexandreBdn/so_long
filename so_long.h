/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:28:35 by abaudin           #+#    #+#             */
/*   Updated: 2023/09/07 09:28:38 by abaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mini/minilibx/mlx.h"

typedef enum e_touch
{
	height = 119,
	down = 115,
	right = 100,
	left = 97,
	escape = 65307
}			t_touch;

typedef struct s_img
{
	char	*floor;
	char	*exit;
	char	*player;
	char	*wall;
	char	*collect;
	char	*playerl;
	char	*playerh;
	char	*playerd;
	char	*enemy;
	int		img_width;
	int		img_height;
	void	*img_floor;
	void	*img_exit;
	void	*img_player;
	void	*img_wall;
	void	*img_collect;
	void	*img_playerh;
	void	*img_playerl;
	void	*img_playerd;
	void	*img_enemy;
}			t_img;

typedef struct s_item
{
	char	player;
	char	playerd;
	char	playerl;
	char	playerh;
	char	exit;
	char	collect;
	char	wall;
	char	floor;
	char	new_floor;
	char	enemy;
	int		count_p;
	int		count_e;
	int		count_c;
}		t_item;

typedef struct s_pos
{
	int	x;
	int	y;
	int	enemy_x;
	int	enemy_y;
}		t_pos;

typedef struct s_game
{
	void	*win_ptr;
	void	*mlx_ptr;
	int		pos_x;
	int		pos_y;
	int		player_mov;
	int		width;
	int		height;
	char	**map;
	char	**copy_map;
	int		movement;
	t_img	img;
	t_pos	pos;
	t_item	content;
}				t_game;

int		key_hook(int key, t_game *game);
int		close_solong(t_game *game);
int		ft_gnl(int fd, char **str);
int		ft_strchr_int(char *str, char *cmp);
int		render(t_game *game);
int		end(t_game *game);
int		ft_check_line(char *map_line, char wall);
int		ft_check_col(char *map_line, char wall, t_game *game);
char	*ft_stradd(char *str, char buff);
char	*ft_itoa(int nbr);
char	*ft_strdup(const char *s);
char	**ft_split(char *s, char c);
char	**map_core(char **str, t_game *game);
char	**parse_map(int fd, t_game *game);
char	*get_map(int fd);
char	**ft_clone(char **t);
void	image_mouv(t_game *game);
void	wall_img(t_game *game);
void	setting(t_item *content);
void	setting_img(t_game *game);
void	*ft_error(char *str);
void	heart_maps(t_game *game);
void	print_remainder(t_game *game);
void	print_background(t_game *game);
void	put_image(t_game *game, void *img, int x, int y);
void	mov_top(t_game *game);
void	mov_bot(t_game *game);
void	mov_right(t_game *game);
void	mov_left(t_game *game);
void	ft_checker_content(t_game *game);
void	check_collect(t_game *game);
void	check_exit(t_game *game);
void	check_aroud_p(t_game *game, int y, int x);
void	free_map_no_launch(char **game);
void	put_image(t_game *game, void *img, int x, int y);
void	mov_enemy(t_game *game);
void	setting_mov(t_game *game);
int		check_symbols(t_game *game);
int		ft_checker_pathvalid(t_game *game);
int		checker_map(t_game *game);
int		count_lines(char **map);
int		check_format(t_game *game);
#endif
