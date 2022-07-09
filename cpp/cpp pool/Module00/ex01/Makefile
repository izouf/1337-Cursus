SRCS	=	contact.cpp phonebook.cpp main.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	Phonebook

all		:	${NAME}

${NAME}	:	${SRCS} contact.hpp phonebook.hpp
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean