CC=g++

CFLAGS=-Wall
LDFLAGS=-lglut -lGL -lGLU -lGLEW -lm -lstdc++
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=app

all: $(SOURCES) $(EXECUTABLE)
	rm *.o

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)

geotest:
	$(CC) $(CFLAGS) geometry.cpp geotest.cpp -o $@

#gcc -o main main.o -lglut -lGL -lGLU -lm -lstdc++ - working command