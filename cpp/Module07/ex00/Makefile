SRCS	=	main.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	 Whatever

all		:	${NAME}

${NAME}	:	${SRCS} whatever.hpp
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean