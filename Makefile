# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 13:13:18 by balnahdi          #+#    #+#              #
#    Updated: 2021/12/30 13:13:19 by balnahdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c commands.c 

OBJ = ${SRC:.c=.o}

CC	= gcc
RM	= rm -f

CFLAG =  -g3 -Wall -Werror -Wextra

all: 
	${MAKE} -C ./libft
	cp ./libft/libft.a ./libft.a 
	${CC} ${CFLAG} ${SRC} libft.a -o pipex

clean: 
	${MAKE} clean -C ./libft
	${RM} ${OBJ}

fclean: clean
	${RM} pipex ./libft.a ./libft/libft.a 

re: fclean all