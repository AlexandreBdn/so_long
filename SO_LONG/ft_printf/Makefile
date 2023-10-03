# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 17:40:29 by abaudin           #+#    #+#              #
#    Updated: 2023/04/28 17:40:30 by abaudin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

SRCS = ft_printf.c 	\
		ft_prc_i.c \
		ft_prc_c.c \
		ft_prc_s.c \
		ft_prc_p.c \
		ft_prc_u.c \
		ft_prc_x.c \
		ft_prc_X.c \
		ft_prc_prc.c \

AR = ar rcs

OBJS =	${SRCS:.c=.o}

CFLAGS= -Wall -Wextra -Werror #-g3 -fsanitize=address

CC = cc

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


${NAME} : ${OBJS}
	$(AR) $(NAME) ${OBJS} 	

all : ${NAME}


#compile: $(OBJS)
#		$(CC) $(CFLAGS) -o a.out $(OBJS)

clean:
	rm -f ${OBJS}

fclean :clean
	rm -f ${NAME}

re: fclean all