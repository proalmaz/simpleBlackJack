NAME = simpleBlackJack.a

SRC =	BJ_utils1.cpp \
		BJ_utils2.cpp \
		blackJack.cpp \

CC = clang++

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}:${OBJS}
	${NAME} ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c -g $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: clean all