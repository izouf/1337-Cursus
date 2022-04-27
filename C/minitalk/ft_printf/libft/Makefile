# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 08:50:10 by izouf             #+#    #+#              #
#    Updated: 2021/11/30 15:07:51 by izouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstnew.c \
		  ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		  ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		  ft_tolower.c ft_toupper.c
OBJS	=	${SRCS:.c=.o}
CC		=	cc 
CFLAGS	= 	-Wall -Wextra -Werror -I.
NAME	=	libft.a
BSRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BOBJS 	=	${BSRCS:.c=.o}
${NAME}	:	${OBJS} libft.h
			ar rc $@ $^
%.o     :   %.c libft.h
			${CC} ${CFLAGS} -c $<
all		:	${NAME} 
bonus	:	${NAME}  ${BOBJS} libft.h
			ar rc  $^
clean	:	
			rm -rf ${OBJS} ${BOBJS}
fclean	: clean
			rm -rf ${NAME}
re		: fclean all
.PHONY	:	all clean bonus fclean re

