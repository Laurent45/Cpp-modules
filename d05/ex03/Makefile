# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 08:04:56 by lfrederi          #+#    #+#              #
#    Updated: 2022/11/15 15:35:32 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Bureaucrat.cpp AForm.cpp\
				  ShrubberyCreationForm.cpp\
				  RobotomyRequestForm.cpp\
				  PresidentialPardonForm.cpp\
				  Intern.cpp

HEADERS			= Bureaucrat.hpp AForm.hpp\
				  ShrubberyCreationForm.hpp\
				  RobotomyRequestForm.hpp\
				  PresidentialPardonForm.hpp\
				  Intern.hpp

OBJS			= ${SRCS:.cpp=.o}

NAME			= intern

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
