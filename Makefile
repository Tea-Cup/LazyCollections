CC=gcc
override FLAGS +=-lstdc++
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

clean:
	rm -rf *.o binary

run:
	./binary
