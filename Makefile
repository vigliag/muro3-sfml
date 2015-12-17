SOURCES=player.cpp util.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sfml-app
CFLAGS=-c -std=c++14 -g
CC=g++
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

TESTSOURCES=tests/utiltest.cpp
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)
TESTEXECUTABLE=tests/test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) main.o
	$(CC) $(LDFLAGS) $(OBJECTS) main.o -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(TESTOBJECTS) $(EXECUTABLE)

build-tests: $(TESTOBJECTS)

$(TESTEXECUTABLE): $(TESTOBJECTS)
	$(CC) $(LDFLAGS) $(TESTOBJECTS) $(OBJECTS) -o $@

test: build-tests $(TESTEXECUTABLE)
	$(TESTEXECUTABLE)

test-debug: build-tests $(TESTEXECUTABLE)
	lldb $(TESTEXECUTABLE)
