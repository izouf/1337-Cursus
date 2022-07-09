SRCS	=	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	Main

all		:	${NAME}

${NAME}	:	${SRCS} Weapon.hpp HumanA.hpp HumanB.hpp
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean