# Makefile v1 — простая сборка без подкаталогов

CXX      = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS  =

PROG = complex.exe
OBJS = mycomplex.o testcmp.o

.PHONY: all clean

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $(OBJS)

mycomplex.o: mycomplex.cpp mycomplex.h
	$(CXX) $(CXXFLAGS) -c mycomplex.cpp

testcmp.o: testcmp.cpp mycomplex.h
	$(CXX) $(CXXFLAGS) -c testcmp.cpp

clean:
	rm -f *.o $(PROG)
