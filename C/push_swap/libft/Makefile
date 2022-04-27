# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 08:50:10 by izouf             #+#    #+#              #
#    Updated: 2021/12/30 17:26:17 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_memcpy.c \
		  ft_memset.c ft_putendl_fd.c ft_split.c ft_strdup.c ft_strjoin.c \
		  ft_error.c ft_max.c ft_isint.c ft_strlen.c ft_strcmp.c get_next_line.c
OBJS	=	${SRCS:.c=.o}
CC		=	gcc -Wall -Wextra -Werror 
NAME	=	libft.a
%.o		: %.c libft.h
			${CC} -c $<
${NAME}	:	${OBJS}
			ar rc $@ $^
all		:	${NAME} 
clean	:	
			rm -rf ${OBJS} ${BOBJS}
fclean	: clean
			rm -rf ${NAME}
re		: fclean all
.PHONY	:	all clean bonus fclean re
