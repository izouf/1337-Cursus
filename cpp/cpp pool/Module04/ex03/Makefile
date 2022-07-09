SRCS	=	main.cpp AMateria.cpp Ice.cpp Cure.cpp  Character.cpp MateriaSource.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	Interface

all		:	${NAME}

${NAME}	:	${SRCS} AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp  MateriaSource.hpp  IMateriaSource.hpp
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean