# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 13:05:29 by lfrederi          #+#    #+#              #
#    Updated: 2022/09/02 13:15:38 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= megaphone.cpp 

OBJS	= ${SRCS:.cpp=.o}

NAME	= megaphone

CC		= c++

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98

.cpp.o:
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
