ODIR = build
_SRCS = ${wildcard src/**/*.c} ${wildcard src/*.c}
SRCS = ${filter-out ${wildcard src/libft/*.c}, ${_SRCS}}
OBJS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS}}
CC = cc
INC = src
CC_FLAGS = -Wextra -Werror -Wall
INCLUDES = ${wildcard src/*.h} ${wildcard src/**/*.h}
RM = rm -rf

NAME = minishell

${ODIR}/%.o: %.c ${INCLUDES}
	@mkdir -p ${@D}
	${CC} ${CC_FLAGS} -c $< -o $@ -I ${INC}

all: ${NAME}

$(NAME): ${OBJS}
	${MAKE} bonus -C src/libft
	${CC} ${OBJS} -L./src/libft -lft -lreadline -o ${NAME}

clean:
	${RM} ${ODIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re bonus all
