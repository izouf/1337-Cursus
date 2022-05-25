SRCS	=	main.cpp Bureaucrat.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	Main

all		:	${NAME}

${NAME}	:	${SRCS} Bureaucrat.hpp 
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean