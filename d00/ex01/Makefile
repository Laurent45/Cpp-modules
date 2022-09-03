# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 13:05:29 by lfrederi          #+#    #+#              #
#    Updated: 2022/09/03 13:24:22 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= Contact.cpp PhoneBook.cpp main.cpp

HEADERS	= PhoneBook.hpp Contact.hpp

OBJS	= ${SRCS:.cpp=.o}

NAME	= phoneBook

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
