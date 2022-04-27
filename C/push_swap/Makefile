# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 14:16:43 by izouf             #+#    #+#              #
#    Updated: 2021/12/30 17:50:46 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/push_swap.c
CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap
BSRCS	=	src/checker.c
BNAME	=	checker
${NAME}	:	source	lft	
			$(CC) $(CFLAGS) ${SRCS} src/push_swap.a libft/libft.a -o $(NAME)

all		:	${NAME}

bonus	:	source lft
			${CC} ${CFLAGS} ${BSRCS} src/push_swap.a libft/libft.a -o ${BNAME}
clean	:
			cd src && make clean
			cd libft && make clean
fclean	:	clean
			cd src && make fclean
			cd libft && make fclean
			rm -rf ${NAME}
			rm -rf ${BNAME}
re		:	fclean all
lft		:	
			cd libft && make
source	:
			cd src && make
.PHONY	:	all clean fclean re
