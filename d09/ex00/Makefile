# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 08:04:56 by lfrederi          #+#    #+#              #
#    Updated: 2023/07/08 10:19:38 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp BitcoinExchange.cpp

HEADERS			= BitcoinExchange.hpp

OBJS			= ${SRCS:.cpp=.o}

NAME			= btc 

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
