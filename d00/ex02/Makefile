# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 13:05:29 by lfrederi          #+#    #+#              #
#    Updated: 2022/09/04 09:03:54 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= Account.cpp tests.cpp

HEADERS	= Account.hpp

OBJS	= ${SRCS:.cpp=.o}

NAME	= tests

CC		= c++

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98

%.o: %.cpp ${HEADERS}
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

all:	${NAME}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
