SRCS	=	megaphone.cpp

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

NAME	=	megaphone

all		:	${NAME}

${NAME}	:	${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean	:
			rm -rf ${NAME}
fclean	:	clean

re		:	fclean all

.Phony	:	all re clean fclean