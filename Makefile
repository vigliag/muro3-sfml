CFLAGS=-c -std=c++14 -g
CC=g++
LD=g++
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SRC=player.cpp util.cpp
BUILDDIR=build
SRCDIR=src
OBJECTS=$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))
EXECUTABLE=$(BUILDDIR)/sfml-app

TESTS=utiltest.cpp
TESTDIR=tests
TESTBUILDDIR=build/tests
TESTOBJECTS=$(patsubst %.cpp, $(TESTBUILDDIR)/%.o, $(TESTS))
TESTEXECUTABLE=$(TESTBUILDDIR)/utiltest



$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) $(BUILDDIR)/main.o -o $@

$(BUILDDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TESTBUILDDIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all build-tests run-tests debug-tests clean

all: $(EXECUTABLE)

build-tests: $(TESTOBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(TESTOBJECTS) $(OBJECTS) -o $(TESTEXECUTABLE)

run-tests: build-tests
	$(TESTEXECUTABLE)

debug-tests: build-tests
	lldb $(TESTEXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE)

clean:
	rm build/tests/* build/* 
