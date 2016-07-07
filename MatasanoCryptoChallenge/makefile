CC=g++
CFLAGS=-std=c++11 
ODIR=obj

.PHONY: all clean 

all: bin/challenge1.exe bin/challenge2.exe bin/challenge3.exe bin/unittests.exe
	@echo Done

bin:
	@mkdir -p bin

bin/unittests.exe: unittests.cpp hexconverter.cpp b64converter.cpp | bin
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $^ -o $@

bin/challenge1.exe: challenge1.cpp hexconverter.cpp b64converter.cpp | bin
	$(CC) $(CFLAGS) $^ -o $@

bin/challenge2.exe: challenge2.cpp hexconverter.cpp b64converter.cpp | bin
	$(CC) $(CFLAGS) $^ -o $@

bin/challenge3.exe:	challenge3.cpp hexconverter.cpp b64converter.cpp | bin
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	@rm -r ./bin	
