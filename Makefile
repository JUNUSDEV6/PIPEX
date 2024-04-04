NAME = pipex
SRCS = pipex.c pipex_utils.c put_fd.c ft_split.c str_utils.c

OBJS = ${SRCS:.c=.o}
CC = gcc -g 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re