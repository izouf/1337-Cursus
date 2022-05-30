SRCS	=	main.cpp A.cpp B.cpp C.cpp Base.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	Dynamic

all		:	${NAME}

${NAME}	:	${SRCS} A.hpp B.hpp C.hpp Base.hpp
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean