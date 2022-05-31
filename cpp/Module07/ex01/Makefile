SRCS	=	main.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	 Iter

all		:	${NAME}

${NAME}	:	${SRCS} iter.hpp
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean