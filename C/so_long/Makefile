# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 10:20:43 by izouf             #+#    #+#              #
#    Updated: 2022/01/13 11:39:36 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/check_map.c src/so_long.c src/utils.c src/herewego.c src/print.c \
			src/hook2.c src/close.c src/move.c src/enemy.c src/boss.c src/free.c
#OBJS	=	${SRCS:.c=.o}
BSRCS	=	src/check_map2.c src/so_long.c src/utils.c src/herewego.c src/print.c \
            src/hook.c src/close.c src/move.c src/enemy.c src/boss.c src/free.c
#BOBJS	=	${BSRCS:.c=.o}
CFLAGS 	=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit  -D BUFFER_SIZE=42
CC		=	cc
NAME	=	so_long
BNAME	=	so_long_bonus

all     :	${NAME}
${NAME} :	lft includes/so_long.h
		${CC} ${CFLAGS} ${SRCS} libft/libft.a get_next_line/*.c -o $@
		
${BNAME}:	lft includes/so_long.h
		${CC} ${CFLAGS} ${BSRCS} libft/libft.a get_next_line/*.c -o $@
bonus	:	${BNAME}
clean	:
			cd libft && make clean
fclean	:	clean
			cd libft && make fclean
			rm -rf ${NAME}
			rm -rf ${BNAME}
re		:	fclean all
lft		:	
			cd libft	&& make
.PHONY	:	all clean fclean re
