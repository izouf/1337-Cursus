# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 13:32:59 by izouf             #+#    #+#              #
#    Updated: 2021/12/30 14:27:04 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	command.c creator.c direction.c free.c index.c markup.c ps.c \
			rotate.c solve.c solve_a.c solve_b.c stack.c validate_stack.c
OBJS	=	${SRCS:.c=.o}
CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc
NAME	=	push_swap.a
${NAME}	:	${OBJS}
			ar rc $@ $^
%.o		:	%.c ../includes/push_swap.h
			${CC}  ${CFLAGS} -c $<
all		:	${NAME}
clean	:
			rm -rf ${OBJS}
fclean	:	clean
			rm -rf ${NAME}
re		: 	fclean all
.PHONY	:	all clean fclean re
	

