# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 05:27:27 by fech-cha          #+#    #+#              #
#    Updated: 2022/06/27 15:21:55 by mzarhou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ODIR = build
_SRCS = ${wildcard src/**/*.c} ${wildcard src/*.c}
SRCS = ${filter-out ${wildcard src/libft/*.c}, ${_SRCS}}
OBJS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS}}
CC = cc
INC = src
CC_FLAGS = -Wextra -Werror -Wall -g
INCLUDES = ${wildcard src/*.h} ${wildcard src/**/*.h}
RM = rm -rf

NAME = minishell

${ODIR}/%.o: %.c ${INCLUDES}
	@mkdir -p ${@D}
	${CC} ${CC_FLAGS} -c $< -o $@ -I ${INC}

all: ${NAME}

$(NAME): ${OBJS}
	${MAKE} -C src/libft
	${CC} ${OBJS} -L./src/libft -lft -lreadline -o ${NAME}

clean:
	${MAKE} clean -C src/libft
	${RM} ${ODIR}

fclean: clean
	${MAKE} fclean -C src/libft
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re bonus all
