# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 08:50:10 by izouf             #+#    #+#              #
#    Updated: 2021/11/30 18:52:37 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS	=	ft_printf.c
OBJS	=	${SRCS:.c=.o}
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.
NAME	=	libftprintf.a
BOBJS 	=	${BSRCS:.c=.o}

%.o		:	%.c includes/ft_printf.h
	${CC} ${CFLAGS} -c $< 
${NAME}	:	source  lft ${OBJS}
			ar rc $(NAME) $(OBJS) src/*.o libft/*.o
all		:	${NAME}
bonus	:	all
clean	:	
			cd src && make clean
			cd libft && make clean
			rm -rf ${OBJS}
fclean	:	clean
			cd src && make  fclean
			cd libft && make fclean
			rm -rf ${NAME}
re		:	fclean all

lft	:
		cd libft && make
source:
		cd src && make
.PHONY	:	all clean bonus fclean re

