# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 06:35:26 by abaudin           #+#    #+#              #
#    Updated: 2023/09/01 06:35:27 by abaudin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
	     
SRC = so_long.c \
	asset/moov.c\
	maps/read_map.c\
	maps/heart_maps.c\
	maps/mov_player.c\
	maps/checker_map.c\
	setting/setting.c\
	ft_printf/ft_printf.c\
	ft_printf/ft_prc_s.c\
	ft_printf/ft_prc_i.c\
	ft_printf/ft_prc_p.c\
	ft_printf/ft_prc_prc.c\
	ft_printf/ft_prc_c.c\
	ft_printf/ft_prc_u.c\
	ft_printf/ft_prc_x.c\
	ft_printf/ft_prc_X.c\
	get_next_line/ft_gnl.c\
	get_next_line/get_next_line_utils.c\
	utils/ft_strdup.c\
	utils/ft_split.c\
	utils/ft_strchr_int.c\
	utils/ft_error.c\
	


CFLAGS	= -Wall -Werror -Wextra -g3
# MLX = -lmini/minilibx  -lXext -lX11 -lz -lm -I/usr/include

OBJS = $(patsubst %.c,%.o,$(SRC))



CC = cc
all : ${NAME}

.c.o :
	$(CC) $(CFLAGS) -I/usr/include -Imini/minilibx -c $< -o $(<:.c=.o)
	
${NAME} : ${OBJS} 
	$(CC) $(CFLAGS)  $(OBJS) -Lmini/minilibx -lmlx_Linux  -L/usr/lib -Imini/minilibx -lXext -lX11 -lz -lm  -o $(NAME)



clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
