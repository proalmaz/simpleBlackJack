NAME = simpleBlackJack

SRC =	BJ_utils1.cpp \
		BJ_utils2.cpp \
		blackJack.cpp \

CC = clang++

OBJS = ${SRC:%.cpp=%.o}

all: ${NAME}

${NAME}:${OBJS}
	$(CC) ${OBJS} -o ${NAME}

%.o: %.c
	$(CC) -c -g $< -o $@

run: all
	clear && make clean && ./$(NAME)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf $(NAME)