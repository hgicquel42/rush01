NAME = rush-01

all: ${NAME}

${NAME}:
	gcc src/*.c -I src/ft.h -o ${NAME}

clean:
	rm ${NAME}

re: clean all