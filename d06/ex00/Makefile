# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 08:04:56 by lfrederi          #+#    #+#              #
#    Updated: 2022/11/18 11:36:05 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp\
				  literalType.cpp\
				  convertChar.cpp convertInt.cpp convertFloat.cpp convertDouble.cpp

HEADERS			= literalType.hpp convert.hpp

OBJS			= ${SRCS:.cpp=.o}

NAME			= convert

CC				= c++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98

%.o: %.cpp ${HEADERS} 
		${CC} ${CFLAGS}	-c $< -o ${<:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS} 
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS} 

fclean:	clean 
		${RM} ${NAME} 

re:		fclean all

.PHONY: all clean fclean re
