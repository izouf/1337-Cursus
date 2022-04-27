# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 16:35:30 by momayaz           #+#    #+#              #
#    Updated: 2022/04/26 16:36:31 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/parsing/check_clr.c \
		src/parsing/check_map.c \
		src/parsing/cub.c \
		src/parsing/pars_line.c \
		src/parsing/split.c \
		src/parsing/utils.c \
		src/parsing/utils1.c \
		src/parsing/utils2.c \
		src/raycasting/dda.c \
		src/raycasting/herewego.c \
		src/raycasting/init.c \
		src/raycasting/minimap.c \
		src/raycasting/mouse.c \
		src/raycasting/move.c \
		src/raycasting/sprite.c \
		src/raycasting/utils.c \
		src/raycasting/utils2.c \

CFLAGS	= -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

CC		=	cc

MANDF	=	src/raycasting/cub3d.c

BONF	=	src/raycasting/cub3d_bonus.c

NAME	=	cub3d

BNAME	=	cub3d_bonus

all		:	${NAME}

${NAME}	:	${MANDAF} ${SRCS} src/raycasting/cub3d.h
	${CC} ${CFLAGS} ${MANDF} ${SRCS} -o ${NAME}

bonus	:	${BNAME}

${BNAME}:	${BONF} ${SRCS} src/raycasting/cub3d.h
	${CC} ${CFLAGS} ${BONF} ${SRCS} -o ${BNAME}
clean	:
			rm -rf ${NAME}
			rm -rf ${BNAME}

fclean	:	clean

re		:	fclean all

.PHONY	:	all bonus re clean fclean
