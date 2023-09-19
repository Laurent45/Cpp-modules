# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 08:04:56 by lfrederi          #+#    #+#              #
#    Updated: 2023/09/19 16:15:17 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp PmergeMe.cpp

HEADERS		= PmergeMe.hpp 

OBJS			= ${SRCS:.cpp=.o}

NAME			= PmergeMe 

CC				= c++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98 -g

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
