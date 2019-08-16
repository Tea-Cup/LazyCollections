CC=g++
override FLAGS +=-std=c++17 -Wall
SOURCES=main.cpp
EXECUTABLE=binary
TEST=test

.PHONY: test build

all: build

build:
	$(CC) $(FLAGS) $(SOURCES) -o ${EXECUTABLE}

test:
	${CC} ${FLAGS} tests/*.cpp -o ${TEST}
	./${TEST}

clean:
	rm -rf ${EXECUTABLE} ${TEST}

run:
	./${EXECUTABLE}
