# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 11:20:49 by izouf             #+#    #+#              #
#    Updated: 2022/01/19 18:03:06 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc -Wall -Wextra -Werror
NAME1		=	client
NAME2		=	server
BNAME1		=	client_bonus
BNAME2		=	server_bonus
all			:	ftprintf ${NAME1} ${NAME2}
${NAME1}	:	minitalk.h 
				${CC} ${CFLAGS} client.c ft_printf/libftprintf.a -o $@
${NAME2}	:	minitalk.h 
				${CC} ${CFLAGS} server.c ft_printf/libftprintf.a -o $@
bonus		:	ftprintf ${BNAME1} ${BNAME2}
${BNAME1}	:	minitalk.h
				${CC} ${CFLAGS} client.c ft_printf/libftprintf.a -o ${BNAME1}
${BNAME2}	:	minitalk.h
				${CC} ${CFLAGS} server.c ft_printf/libftprintf.a -o ${BNAME2}
clean		:	
				cd ft_printf && make clean
fclean		:	clean
				cd ft_printf && make fclean
				rm -rf client
				rm -rf client_bonus
				rm -rf server
				rm -rf server_bonus
re			:	fclean all
ftprintf	:
				cd ft_printf && make	
