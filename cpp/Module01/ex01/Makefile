SRCS	=	Zombie.cpp main.cpp zombieHorde.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	Zombie

all		:	${NAME}

${NAME}	:	${SRCS} Zombie.hpp
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean