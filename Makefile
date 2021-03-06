CC=g++
CFLAGS=-c -Wall -ggdb -I. --coverage -O0 -v
LDFLAGS=--coverage
SOURCES=heapsandbox.cpp MaxHeap.h
EXECUTABLE=heapsandbox 
TESTS=MaxHeap_test.h

OBJECTS=$(SOURCES:.cpp=.o)

FLAGS   = -Iinclude

all: $(SOURCES) $(EXECUTABLE)
	
# These next lines do a bit of magic found from http://stackoverflow.com/questions/2394609/makefile-header-dependencies
# Essentially it asks the compiler to read the .cpp files and generate the needed .h dependencies.
# This way if any .h file changes the correct .cpp files will be recompiled
depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ >> ./.depend;

include .depend
# End .h file magic

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
	rm -f ./.depend
	rm -f testrunner*
	rm -f labtestrunner*
	rm -f suggest
	
# CXX Testing	
CXXLOCATION = cxxtest
CXXTESTGEN = $(CXXLOCATION)/bin/cxxtestgen

test: testrunner 
	./testrunner
	

testrunner: testrunner.cpp $(OBJECTS)
	g++ -v --coverage -I. -ggdb -Wall -I$(CXXLOCATION)/ -o testrunner testrunner.cpp 
	

testrunner.cpp: $(HEADERS) $(TESTSSOURCES) $(SOURCES) $(TESTS)
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)

