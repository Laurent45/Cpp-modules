# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 08:04:56 by lfrederi          #+#    #+#              #
#    Updated: 2022/11/09 11:49:16 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp\
				  AMateria.cpp Ice.cpp Cure.cpp\
				  Character.cpp\
				  MateriaSource.cpp

HEADERS			= AMateria.hpp Ice.hpp Cure.hpp\
				  ICharacter.hpp IMateriaSource.hpp\
				  Character.hpp MateriaSource.hpp

OBJS			= ${SRCS:.cpp=.o}

NAME			= exe

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
