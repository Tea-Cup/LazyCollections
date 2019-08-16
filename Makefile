CC=g++
override FLAGS +=-std=c++17 -lstdc++
override CFLAGS +=${FLAGS} -c -Wall
override LDFLAGS +=${FLAGS}
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=binary

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: test
test:
	g++ tests.cpp -o test
	./test

clean:
	rm -rf *.o binary test

run:
	./binary
