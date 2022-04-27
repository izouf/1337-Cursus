# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 08:50:10 by izouf             #+#    #+#              #
#    Updated: 2021/12/30 13:52:08 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS	=	 ft_convertd.c ft_convertper.c ft_convertu.c ft_flags.c ft_herewego.c ft_putnchar_fd.c ft_width.c \
			 ft_convertc.c ft_convertp.c ft_converts.c ft_convertx.c ft_formselect.c ft_precision.c
OBJS	=	${SRCS:.c=.o}
CFLAGS	=	-Wall -Wextra -Werror -I.
CC		= 	cc
NAME	=	libftprintf.a
BOBJS 	=	${BSRCS:.c=.o}
${NAME}	:	${OBJS}
			ar rc $@ $^
%.o     :   %.c ../includes/ft_printf.h
			${CC} -c ${CFLAGS} $<
all		:	${NAME} 
clean	:	
			rm -rf ${OBJS}
fclean	: clean
			rm -rf ${NAME}
re		: fclean all
.PHONY	:	all clean bonus fclean re

