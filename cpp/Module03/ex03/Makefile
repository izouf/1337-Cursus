SRCS	=	ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	Main

all		:	${NAME}

${NAME}	:	${SRCS} ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean