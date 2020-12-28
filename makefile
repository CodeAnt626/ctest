.PHONY:clean

all: ./src/test.o main.o
	gcc ./src/test.o main.o -o ./bin/main

./src/test.o: ./src/test.c ./include/test.h
	gcc -I./include -c ./src/test.c -o ./src/test.o

main.o: main.c ./include/test.h
	gcc -I./include -c main.c

run: all
	./bin/main

clean:
	rm ./bin/main ./src/*.o ./*.o
