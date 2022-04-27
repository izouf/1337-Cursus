# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 09:41:29 by izouf             #+#    #+#              #
#    Updated: 2022/03/03 11:55:20 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/main.c src/activity.c src/parse_init.c  src/check.c
OBJS	=	${SRCS:.c=.o}
NAME	=	philo_bonus
CC		=	cc
CFLAGS	=	-Werror -Wall -Wextra -pthread

all		:	${NAME}
${NAME}	:	${OBJS} includes/philo_bonus.h
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
clean	:
			rm -rf ${OBJS}
fclean	:	clean
			rm -rf ${NAME}
re		:	fclean all
